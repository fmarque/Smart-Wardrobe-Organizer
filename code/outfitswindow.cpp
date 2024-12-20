#include "outfitswindow.h"
#include "ui_outfitswindow.h"
#include "clothingitemswindow.h"
#include "closetwindow.h"
#include "mainmenuwindow.h"
#include "global.h"  // To access ClosetManager and Outfit data

OutfitsWindow::OutfitsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OutfitsWindow)
{
    ui->setupUi(this);

    // Call the populateOutfitDropdown method to populate the combo box with saved outfits
    populateOutfitDropdown();
    // Call the loadOutfits method to populate the combo box with saved outfits
    loadOutfits();
}

OutfitsWindow::~OutfitsWindow()
{
    delete ui;
}

// Open the Clothing Items window upon click
void OutfitsWindow::on_viewClothingItems_button_clicked()
{
    this->hide();  // Hide the current window
    ClothingItemsWindow *CIWindow = new ClothingItemsWindow(this);
    CIWindow->show();  // Show the new window
}

// Open the Closet window upon click
void OutfitsWindow::on_viewCloset_button_clicked()
{
    this->hide();  // Hide the current window
    ClosetWindow *closetWindow = new ClosetWindow(this);
    closetWindow->show();  // Show the new window
}

// Open the Main Menu window upon click
void OutfitsWindow::on_backToMainMenu_button_clicked()
{
    this->hide();  // Hide the current window
    MainMenu *mainMenuWindow = new MainMenu(this);
    mainMenuWindow->show();  // Show the new window
}

void OutfitsWindow::loadOutfits() {
    // Clear old outfit boxes from the grid layout inside the scroll area
    QLayout *layout = ui->outfitsScrollArea->widget()->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();  // Delete the old widgets
            delete item;  // Delete the layout item
        }
    }

    // Get the list of saved outfits from your ClosetManager or data source
    auto outfits = ClosetManager::getInstance()->getSavedOutfits();

    // Populate the combo box with outfit names
    ui->comboBox->clear();  // Clear previous entries
    for (const auto& outfit : outfits) {
        ui->comboBox->addItem(QString::fromStdString(outfit.name));
    }

    // Add outfit display (optional)
    int numOutfits = outfits.size();
    int numColumns = 3;  // Adjust this depending on how many columns you want per row
    int row = 0, column = 0;

    // Loop through the list of outfits
    for (const auto& outfit : outfits) {
        QWidget *outfitWidget = new QWidget(ui->outfitsScrollArea->widget());
        outfitWidget->setFixedSize(220, 600);  // Adjusted height for all images to fit better
        outfitWidget->setStyleSheet("background: transparent; border: none;");

        QLabel *outfitNameLabel = new QLabel(QString::fromStdString(outfit.name), outfitWidget);
        outfitNameLabel->setAlignment(Qt::AlignCenter);
        outfitNameLabel->setStyleSheet("font-weight: bold; font-size: 14px; color: #333;");
        outfitNameLabel->setGeometry(10, 10, 200, 20);

        QLabel *coatImageLabel = new QLabel(outfitWidget);
        QPixmap coatImage(QString::fromStdString(outfit.coatName));
        coatImageLabel->setPixmap(coatImage.scaled(180, 180, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        coatImageLabel->setGeometry(10, 20, 180, 180);

        QLabel *topImageLabel = new QLabel(outfitWidget);
        QPixmap topImage(QString::fromStdString(outfit.topName));
        topImageLabel->setPixmap(topImage.scaled(180, 180, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        topImageLabel->setGeometry(10, 160, 180, 180);

        QLabel *bottomImageLabel = new QLabel(outfitWidget);
        QPixmap bottomImage(QString::fromStdString(outfit.bottomName));
        bottomImageLabel->setPixmap(bottomImage.scaled(180, 180, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        bottomImageLabel->setGeometry(10, 270, 180, 180);

        QLabel *shoeImageLabel = new QLabel(outfitWidget);
        QPixmap shoeImage(QString::fromStdString(outfit.shoeName));
        shoeImageLabel->setPixmap(shoeImage.scaled(110, 110, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        shoeImageLabel->setGeometry(10 + (180 - 110) / 2, 410, 110, 110);

        QGridLayout *gridLayout = qobject_cast<QGridLayout *>(ui->outfitsScrollArea->widget()->layout());
        if (gridLayout) {
            gridLayout->addWidget(outfitWidget, row, column);
        }

        topImageLabel->raise();
        coatImageLabel->raise();

        column++;
        if (column >= numColumns) {
            column = 0;
            row++;
        }
    }
}

void OutfitsWindow::on_deleteOutfitButton_clicked()
{
    // Get the selected outfit name from the combo box
    QString selectedOutfitName = ui->comboBox->currentText();

    // Call ClosetManager's delete function (you need to implement this)
    ClosetManager::getInstance()->removeOutfit(selectedOutfitName.toStdString());

    // Refresh the list after deleting the outfit
    loadOutfits();
}

void OutfitsWindow::populateOutfitDropdown() {
    // Get the list of saved outfits from your ClosetManager or data source
    auto outfits = ClosetManager::getInstance()->getSavedOutfits();

    // Populate the combo box with outfit names
    ui->comboBox->clear();  // Clear previous entries
    for (const auto& outfit : outfits) {
        ui->comboBox->addItem(QString::fromStdString(outfit.name));
    }
}

