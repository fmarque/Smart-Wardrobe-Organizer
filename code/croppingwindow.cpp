#include "croppingwindow.h"
#include "ui_croppingwindow.h" // Include the auto-generated UI header
#include "closetmanager.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QLayout>


// TO FIX: if image is too big or too small, standardize image uploads

CroppingWindow::CroppingWindow(ClosetManager* manager, const QString &filePath, const QString &type, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CroppingWindow), closetManager(manager), filePath(filePath), type(type), drawing(false) {
    ui->setupUi(this);

    // Ensure the photoLayout exists in the .ui file
    if (!ui->photoLayout) {
        qDebug() << "photoLayout is not defined in the .ui file!";
        return;
    }

    // Initialize the scene and view
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setDragMode(QGraphicsView::NoDrag);
    view->setObjectName("graphicsView");
    //view->installEventFilter(this);
    //NEWWWWW
    view->viewport()->installEventFilter(this);
    view->setFocusPolicy(Qt::StrongFocus);
    view->setInteractive(true); // Allow interaction with items in the scene
    view->setMouseTracking(true); // Ensure mouse move events are captured
    ui->photoLayout->setContentsMargins(0, 0, 0, 0);
    ui->photoLayout->setSpacing(0);

    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    //NEWWWWW
    view->viewport()->setAttribute(Qt::WA_TransparentForMouseEvents, false);


    // Load the image into the pixmap
    originalPixmap = QPixmap(filePath);
    if (!originalPixmap.isNull()) {
        scene->addPixmap(originalPixmap);
    } else {
        qDebug() << "Failed to load image from file:" << filePath;
        return; // Exit constructor if image loading fails
    }

    // Add the QGraphicsView to the photoLayout
    ui->photoLayout->addWidget(view);

    // Initialize the lasso path and path item
    lassoPath = QPainterPath();
    pathItem = new QGraphicsPathItem();
    pathItem->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    scene->addItem(pathItem);

    // Connect the buttons to their slots
    connect(ui->saveCropButton, &QPushButton::clicked, this, &CroppingWindow::saveCrop);
    connect(ui->resetLassoButton, &QPushButton::clicked, this, &CroppingWindow::resetLasso);

    // Make sure pixmap works
    if (!originalPixmap.isNull()) {
        qDebug() << "Loaded original pixmap with size:" << originalPixmap.size();
    } else {
        qDebug() << "Failed to load original pixmap.";
    }



    setWindowTitle("Crop Image");
    resize(800, 600);
}

// Destroyers
CroppingWindow::~CroppingWindow() {
    delete ui;
    delete scene;
    delete view;
}

// Start up the Lasso tool upon mouse click
void CroppingWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = true;
        //QPointF scenePos = view->mapToScene(event->pos());
        QPointF scenePos = view->mapToScene(view->viewport()->mapFromGlobal(event->globalPos()));

        lassoPath = QPainterPath(); // Reset the lasso path
        lassoPath.moveTo(scenePos);
        pathItem->setPath(lassoPath);
        qDebug() << "Press:" << scenePos;
        QWidget *child = childAt(event->pos());
        qDebug() << "Mouse pressed at:" << event->pos() << "on widget:" << (child ? child->objectName() : "No child");
    }
}

// Set necessary Lasso paths upon mouse dragging
void CroppingWindow::mouseMoveEvent(QMouseEvent *event) {
    if (drawing) {
        //QPointF scenePos = view->mapToScene(event->pos());
        QPointF scenePos = view->mapToScene(view->viewport()->mapFromGlobal(event->globalPos()));

        lassoPath.lineTo(scenePos); // Extend the lasso path
        pathItem->setPath(lassoPath); // Update the path in the pathItem
        qDebug() << "Lasso extended to:" << scenePos;
    }
}

// Allow user to stop drawing with Lasso if they let go of mouse button
void CroppingWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = false;
    }
}

// Reset the path made by the Lasso upon user click
void CroppingWindow::resetLasso() {
    lassoPath = QPainterPath(); // Clear the lasso path
    pathItem->setPath(lassoPath); // Clear the path item
    qDebug() << "Lasso path reset.";
}

// BUG: incrementing by 2 instead of 1, cant not increment bc s
// Saves the cropped image made by Lasso
void CroppingWindow::saveCrop() {
    if (lassoPath.isEmpty()) {
        qDebug() << "Lasso path is empty! Nothing to crop.";
        return;
    }

    QImage cropped = cropImage();
    if (!cropped.isNull()) {
        // Save cropped image temporarily
        QString tempDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
        QString tempFilePath = tempDir + "/temp_cropped_image.png";
        if (!cropped.save(tempFilePath)) {
            qDebug() << "Failed to save temporary cropped image.";
            return;
        }

        if (!tempFilePath.isEmpty()) {
            cropped.save(tempFilePath);

                qDebug() << "Temporary cropped image saved to:" << tempFilePath;

            if (closetManager) {
                qDebug() << "ClosetManager instance is valid. Calling uploadTest...";
                closetManager->uploadTest(tempFilePath.toStdString(), type.toStdString());
            } else {
                qDebug() << "ClosetManager instance is null!";
            }
        emit imageCropped(tempFilePath);  // Notify other components
        close();
        }

    } else {
        qDebug() << "No valid crop path.";
    }
}


// Crops the path made by Lasso into the image
QImage CroppingWindow::cropImage() {
    if (lassoPath.isEmpty() || originalPixmap.isNull()) {
        qDebug() << "Invalid cropping path or image.";
        return QImage();
    }

    QImage croppedImage(originalPixmap.size(), QImage::Format_ARGB32);
    croppedImage.fill(Qt::transparent);

    QPainter painter(&croppedImage);
    painter.setClipPath(lassoPath); // Clip to the lasso path
    painter.drawPixmap(0, 0, originalPixmap); // Draw the clipped image
    painter.end();

    // const int STANDARD_WIDTH = 300;
    // const int STANDARD_HEIGHT = 300;
    // QImage resizedImage = croppedImage.scaled(STANDARD_WIDTH, STANDARD_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // qDebug() << "Image cropped successfully.";
    //TODO: fill space before displaying, likely different for each, bc diff size image

    const int STANDARD_WIDTH = 220;
    const int STANDARD_HEIGHT = 220;
    QImage resizedImage = croppedImage.scaled(STANDARD_WIDTH, STANDARD_HEIGHT, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //return croppedImage;
    return resizedImage;
}


// Ensure proper area is being access with Lasso tool
bool CroppingWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == view->viewport()) {
        if (event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::MouseMove ||
            event->type() == QEvent::MouseButtonRelease) {

            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

            // Forward to mouse event handlers
            if (event->type() == QEvent::MouseButtonPress) mousePressEvent(mouseEvent);
            if (event->type() == QEvent::MouseMove) mouseMoveEvent(mouseEvent);
            if (event->type() == QEvent::MouseButtonRelease) mouseReleaseEvent(mouseEvent);

            return true; // Indicate event is handled
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

