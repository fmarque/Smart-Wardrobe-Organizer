#include "clothingitemswindow.h"
#include "ui_clothingitemswindow.h"

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
