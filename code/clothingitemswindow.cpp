#include "clothingitemswindow.h"
#include "ui_clothingitemswindow.h"
#include "outfitswindow.h"  // Include here to define OutfitsWindow


ClothingItemsWindow::ClothingItemsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClothingItemsWindow)
{
    ui->setupUi(this);
}

ClothingItemsWindow::~ClothingItemsWindow()
{
    delete ui;
}

void ClothingItemsWindow::on_viewClothingItems_button_clicked()
{
    this->hide();  // Hide the current window
    OutfitsWindow *outfitsWindow = new OutfitsWindow(this);  // Create a new OutfitsWindow
    outfitsWindow->show();  // Show the new window
}

