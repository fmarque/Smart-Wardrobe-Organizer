#include "closetwindow.h"
#include "ui_closetwindow.h"
#include "ui_popup1.h"
#include <QFileDialog>
#include "clothingitemswindow.h"
#include "outfitswindow.h"
#include "closetmanager.h"

ClosetWindow::ClosetWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClosetWindow)
    , popUp(new QWidget(this)) // Initialize the pop-up as a child of ClosetWindow
{
    ui->setupUi(this);

    // Set up the pop-up widget using the generated PopUp1 UI
    Ui::popup1 popUpUi;
    popUpUi.setupUi(popUp);
    popUp->setWindowFlags(Qt::Popup); // Set it to behave like a pop-up

    // Connect the button in ClosetWindow to show the pop-up when clicked
    connect(ui->uploadButton, &QPushButton::clicked, [this]() {
        // Position the pop-up near the button when clicked
        QPoint pos = ui->uploadButton->mapToGlobal(QPoint(0, ui->uploadButton->height()));
        popUp->move(pos);
        popUp->show();
    });

    // Connect each button in the pop-up to openFileDialog with a different identifier
    connect(popUpUi.coatButton, &QPushButton::clicked, this, [this]() { openFileDialog("coat"); });
    connect(popUpUi.topButton, &QPushButton::clicked, this, [this]() { openFileDialog("top"); });
    connect(popUpUi.bottomButton, &QPushButton::clicked, this, [this]() { openFileDialog("bottom"); });
    connect(popUpUi.shoesButton, &QPushButton::clicked, this, [this]() { openFileDialog("shoes"); });
}

// Destroyers
ClosetWindow::~ClosetWindow()
{
    delete ui;
    delete popUp;
}

// Connect the cropping and saving mechanism from Closet window to Closet Manager and Cropping Class
void ClosetWindow::openFileDialog(const QString &buttonType)
{
    // Open the file dialog and get the selected file path
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Images (*.png *.jpg *.jpeg)"));
    // Check if a file was selected
    if (!filePath.isEmpty()) {
        CroppingWindow* cropWindow = new CroppingWindow(ClosetManager::getInstance(), filePath, buttonType, this);

        // Connect cropping signal to handle cropped image
        connect(cropWindow, &CroppingWindow::imageCropped, this, [this, buttonType](const QString &croppedPath) {
            // Upload cropped image and save metadata
            ClosetManager::getInstance()->uploadTest(croppedPath.toStdString(), buttonType.toStdString());
        });
        cropWindow->show();
    }
}

// Open the Clothing Items window upon click
void ClosetWindow::on_pushButton_3_clicked()
{
    this->hide();  // Hide the current window
    ClothingItemsWindow *CIWindow = new ClothingItemsWindow(this);
    CIWindow->show();  // Show the new window
}

// Open the Outfits window upon click
void ClosetWindow::on_pushButton_2_clicked()
{
    this->hide();  // Hide the current window
    OutfitsWindow *outfitsWindow = new OutfitsWindow(this);
    outfitsWindow->show();  // Show the new window
}




