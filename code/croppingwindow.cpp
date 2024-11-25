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

// CroppingWindow::CroppingWindow(const QString &filePath, const QString &type, QWidget *parent)
//     : QMainWindow(parent), ui(new Ui::CroppingWindow), filePath(filePath), type(type), drawing(false) {
//     ui->setupUi(this);
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
    //view->setInteractive(false); // Disable interaction to prevent interference    NEWLY ADDED
    view->setRenderHint(QPainter::Antialiasing);
    view->setDragMode(QGraphicsView::NoDrag);

    view->setObjectName("graphicsView");

    view->installEventFilter(this);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



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

    // pure debugging
    if (!originalPixmap.isNull()) {
        qDebug() << "Loaded original pixmap with size:" << originalPixmap.size();
    } else {
        qDebug() << "Failed to load original pixmap.";
    }



    setWindowTitle("Crop Image");
    resize(800, 600);
}



CroppingWindow::~CroppingWindow() {
    delete ui;
    delete scene;
    delete view;
}

void CroppingWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = true;
        QPointF scenePos = view->mapToScene(event->pos());
        lassoPath = QPainterPath(); // Reset the lasso path
        lassoPath.moveTo(scenePos);
        pathItem->setPath(lassoPath);
        qDebug() << "Press:" << scenePos;
        QWidget *child = childAt(event->pos());
        qDebug() << "Mouse pressed at:" << event->pos() << "on widget:" << (child ? child->objectName() : "No child");
    }
}

void CroppingWindow::mouseMoveEvent(QMouseEvent *event) {
    if (drawing) {
        QPointF scenePos = view->mapToScene(event->pos());
        lassoPath.lineTo(scenePos); // Extend the lasso path
        pathItem->setPath(lassoPath); // Update the path in the pathItem
        qDebug() << "Lasso extended to:" << scenePos;
    }
}

void CroppingWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = false;
    }
}

void CroppingWindow::resetLasso() {
    lassoPath = QPainterPath(); // Clear the lasso path
    pathItem->setPath(lassoPath); // Clear the path item
    qDebug() << "Lasso path reset.";
}

// void CroppingWindow::saveCrop() {
//     if (lassoPath.isEmpty()) {
//         qDebug() << "Lasso path is empty! Nothing to crop.";
//         return; // Prevent saving if no lasso path is defined
//     }
//     QImage cropped = cropImage();
//     if (!cropped.isNull()) {
//         QString savePath = QFileDialog::getSaveFileName(this, "Save Cropped Image", "", "Images (*.png *.jpg)");
//         if (!savePath.isEmpty()) {
//             cropped.save(savePath);
//             qDebug() << "Cropped image saved to:" << savePath;

//             if (closetManager) {
//                 qDebug() << "ClosetManager instance is valid. Calling uploadTest...";
//                 closetManager->uploadTest(savePath.toStdString());
//                 closetManager->saveMetadata(savePath.toStdString(), type.toStdString());
//             } else {
//                 qDebug() << "ClosetManager instance is null!";
//             }

//             emit imageCropped(savePath);
//             close();
//         }

//     } else {
//         qDebug() << "No valid crop path.";
//     }
// }


// void CroppingWindow::saveCrop() {
//     if (lassoPath.isEmpty()) {
//         qDebug() << "Lasso path is empty! Nothing to crop.";
//         return; // Prevent saving if no lasso path is defined
//     }

//     QImage cropped = cropImage();
//     if (!cropped.isNull()) {
//         // Save cropped image to a temporary file
//         QString tempDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
//         QString tempFilePath = tempDir + "/temp_cropped_image.png";

//         if (!cropped.save(tempFilePath)) {
//             qDebug() << "Failed to save cropped image to temporary file:" << tempFilePath;
//             return;
//         }

//         qDebug() << "Temporary cropped image saved to:" << tempFilePath;

//         // Use ClosetManager to handle the final path and metadata
//         if (closetManager) {
//             qDebug() << "ClosetManager instance is valid. Calling uploadTest...";
//             closetManager->uploadTest(tempFilePath.toStdString(), type.toStdString()); // Move to the final directory
//             closetManager->saveMetadata(tempFilePath.toStdString(), type.toStdString());
//         } else {
//             qDebug() << "ClosetManager instance is null!";
//         }

//         emit imageCropped(tempFilePath); // Notify other components about the saved image
//         close(); // Automatically close the cropping window
//     } else {
//         qDebug() << "Cropped image is null! Aborting save.";
//     }
// }

// BUG: incrementing by 2 instead of 1, cant not increment bc s
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


// QImage CroppingWindow::cropImage() {
//     if (lassoPath.isEmpty() || originalPixmap.isNull()) {
//         qDebug() << "Invalid cropping path or image.";
//         return QImage();
//     }

//     // Get the bounding rectangle of the lassoPath
//     QRectF cropRect = lassoPath.boundingRect();

//     // Ensure the rectangle is within the image bounds
//     cropRect = cropRect.intersected(originalPixmap.rect());

//     if (cropRect.isEmpty()) {
//         qDebug() << "Crop rectangle is empty or outside image bounds.";
//         return QImage();
//     }

//     // Crop the image using the bounding rectangle
//     QImage croppedImage = originalPixmap.toImage().copy(cropRect.toRect());

//     // Debug: Log cropping details
//     qDebug() << "Crop rectangle:" << cropRect;
//     qDebug() << "Cropped Image Size:" << croppedImage.size();

//     return croppedImage;
// }
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

    qDebug() << "Image cropped successfully.";
    return croppedImage;
}



bool CroppingWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == view) {
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

