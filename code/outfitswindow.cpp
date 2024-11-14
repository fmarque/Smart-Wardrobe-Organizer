#include "outfitswindow.h"
#include "ui_outfitswindow.h"
#include "clothingitemswindow.h"  // Include here to define ClothingItemsWindow

OutfitsWindow::OutfitsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OutfitsWindow)
{
    ui->setupUi(this);
}

OutfitsWindow::~OutfitsWindow()
{
    delete ui;
}

void OutfitsWindow::on_viewClothingItems_button_clicked()
{
    this->hide();  // Hide the current window
    ClothingItemsWindow *CIWindow = new ClothingItemsWindow(this);  // Create a new ClothingItemsWindow
    CIWindow->show();  // Show the new window
}

