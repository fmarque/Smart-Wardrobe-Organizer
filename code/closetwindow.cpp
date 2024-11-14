#include "closetwindow.h"
#include "ui_closetwindow.h"
#include "ui_popup1.h" // Include the header for PopUp1
#include <QFileDialog> // Include the QFileDialog header for file selection
#include "clothingitemswindow.h"
#include "outfitswindow.h"

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

ClosetWindow::~ClosetWindow()
{
    delete ui;
    delete popUp; // Clean up the pop-up widget
}

void ClosetWindow::openFileDialog(const QString &buttonType)
{
    // Open the file dialog and get the selected file path
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("All Files (*.*)"));

    // Check if a file was selected
    if (!filePath.isEmpty()) {
        // Handle the file based on which button was clicked
        if (buttonType == "coat") {
            qDebug() << "Coat file selected: " << filePath;
        } else if (buttonType == "top") {
            qDebug() << "Top file selected: " << filePath;
        } else if (buttonType == "bottom") {
            qDebug() << "Bottom file selected: " << filePath;
        } else if (buttonType == "shoes") {
            qDebug() << "Shoes file selected: " << filePath;
        }
    }
}

void ClosetWindow::on_pushButton_3_clicked()
{
    this->hide();  // Hide the current window
    ClothingItemsWindow *CIWindow = new ClothingItemsWindow(this);  // Create a new OutfitsWindow
    CIWindow->show();  // Show the new window
}


void ClosetWindow::on_pushButton_2_clicked()
{
    this->hide();  // Hide the current window
    OutfitsWindow *outfitsWindow = new OutfitsWindow(this);  // Create a new OutfitsWindow
    outfitsWindow->show();  // Show the new window
}




