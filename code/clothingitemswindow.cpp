#include "clothingitemswindow.h"
#include "ui_clothingitemswindow.h"
#include "outfitswindow.h"  // Include here to define OutfitsWindow
#include "closetwindow.h"
#include "mainmenuwindow.h"
#include "loginWindow.h"
#include "ui_popup1.h"
#include "closetmanager.h"
#include "croppingwindow.h"
#include "global.h"


ClothingItemsWindow::ClothingItemsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClothingItemsWindow)
    , popUp(new QWidget(this))  // Initialize pop-up like in ClosetWindow

{
    ui->setupUi(this);

    // Initialize the pop-up widget for clothing type selection
    Ui::popup1 popUpUi;
    popUpUi.setupUi(popUp);
    popUp->setWindowFlags(Qt::Popup);

    // Connect "Upload Item" button to show the pop-up
    connect(ui->uploadItem_button, &QPushButton::clicked, [this]() {
        QPoint pos = ui->uploadItem_button->mapToGlobal(QPoint(0, ui->uploadItem_button->height()));
        popUp->move(pos);
        popUp->show();
    });

    // Connect pop-up buttons to the openFileDialog
    connect(popUpUi.coatButton, &QPushButton::clicked, this, [this]() { openFileDialog("coat"); });
    connect(popUpUi.topButton, &QPushButton::clicked, this, [this]() { openFileDialog("top"); });
    connect(popUpUi.bottomButton, &QPushButton::clicked, this, [this]() { openFileDialog("bottom"); });
    connect(popUpUi.shoesButton, &QPushButton::clicked, this, [this]() { openFileDialog("shoes"); });
}

// Destroyer
ClothingItemsWindow::~ClothingItemsWindow()
{
    delete ui;
    delete popUp;
}

// Shared file dialog logic
void ClothingItemsWindow::openFileDialog(const QString &buttonType)
{
    popUp->close();  // Close the pop-up

    // Open file dialog to select an image
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Images (*.png *.jpg *.jpeg)"));
    if (!filePath.isEmpty()) {
        // Open CroppingWindow for cropping and uploading
        CroppingWindow* cropWindow = new CroppingWindow(ClosetManager::getInstance(), filePath, buttonType, this);

        // Connect cropping signal to handle upload and refresh
        connect(cropWindow, &CroppingWindow::imageCropped, this, [this, buttonType](const QString &croppedPath) {
            ClosetManager::getInstance()->uploadTest(croppedPath.toStdString(), buttonType.toStdString());
            populateClothingItems(buttonType.toStdString());  // Refresh layout
        });

        cropWindow->show();
    }
}

// Open the Outfits window upon click
void ClothingItemsWindow::on_viewClothingItems_button_clicked()
{
    this->hide();  // Hide the current window
    OutfitsWindow *outfitsWindow = new OutfitsWindow(this);
    outfitsWindow->show();  // Show the new window
}

// Open the Closet window upon click
void ClothingItemsWindow::on_viewCloset_button_clicked()
{
    this->hide();  // Hide the current window
    ClosetWindow *closetWindow = new ClosetWindow(this);
    closetWindow->show();  // Show the new window
}

// Open the Main Menu window upon click
void ClothingItemsWindow::on_backToMainMeny_button_clicked()
{
    this->hide();  // Hide the current window
    MainMenu *mainMenuWindow = new MainMenu(this);
    mainMenuWindow->show();  // Show the new window
}

void ClothingItemsWindow::populateClothingItems(const std::string& type) {
    ClosetManager* manager = ClosetManager::getInstance();
    std::list<ClothingItem*> items = manager->getClothingItemsByType(type);

    // Clear the current layout
    QLayoutItem* child;
    while ((child = ui->clothesLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Define target size for frames
    const QSize targetSize(220, 220);
    int row = 0, col = 0;
    const int maxColumns = 4;

    for (ClothingItem* item : items) {
        QPixmap pixmap(QString::fromStdString(item->getImage()));

        // Ensure scaling to fit QLabel size
        QLabel* imageLabel = new QLabel();
        imageLabel->setFixedSize(targetSize); // Set QLabel size
        imageLabel->setPixmap(pixmap.scaled(targetSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        imageLabel->setAlignment(Qt::AlignCenter);
        imageLabel->setStyleSheet("border: 1px solid gray; background-color: white;");

        // Add QLabel to grid layout
        ui->clothesLayout->addWidget(imageLabel, row, col);

        // Move to next grid position
        col++;
        if (col >= maxColumns) {
            col = 0;
            row++;
        }
    }

    ui->clothesLayout->setSpacing(10);  // Set spacing for a cleaner look
    ui->clothesLayout->setAlignment(Qt::AlignTop);
}



void ClothingItemsWindow::on_pushButton_clicked() {
    populateClothingItems("shoes");
}

void ClothingItemsWindow::on_pushButton_2_clicked() {
    populateClothingItems("bottom");
}

void ClothingItemsWindow::on_pushButton_3_clicked() {
    populateClothingItems("top");
}

void ClothingItemsWindow::on_pushButton_4_clicked() {
    populateClothingItems("coat");
}


void ClothingItemsWindow::on_uploadItem_button_clicked()
{
    // Position the pop-up near the upload button and show it
    QPoint pos = ui->uploadItem_button->mapToGlobal(QPoint(0, ui->uploadItem_button->height()));
    popUp->move(pos);
    popUp->show();
}


