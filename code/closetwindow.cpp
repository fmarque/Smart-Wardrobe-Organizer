#include "closetwindow.h"
#include "ui_closetwindow.h"
#include "clothingitemswindow.h"
#include "outfitswindow.h"

ClosetWindow::ClosetWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClosetWindow)
{
    ui->setupUi(this);
}

ClosetWindow::~ClosetWindow()
{
    delete ui;
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


