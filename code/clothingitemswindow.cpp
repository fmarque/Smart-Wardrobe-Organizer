#include "clothingitemswindow.h"
#include "ui_clothingitemswindow.h"
#include "outfitswindow.h"  // Include here to define OutfitsWindow
#include "closetwindow.h"
#include "mainmenuwindow.h"
#include "loginWindow.h"
#include "global.h"


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


void ClothingItemsWindow::on_viewCloset_button_clicked()
{
    this->hide();  // Hide the current window
    ClosetWindow *closetWindow = new ClosetWindow(this);  // Create a new OutfitsWindow
    closetWindow->show();  // Show the new window
}


void ClothingItemsWindow::on_backToMainMeny_button_clicked()
{
    this->hide();  // Hide the current window
    MainMenu *mainMenuWindow = new MainMenu(this);  // Create a new OutfitsWindow
    mainMenuWindow->show();  // Show the new window
}

