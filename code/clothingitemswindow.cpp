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

// Destroyer
ClothingItemsWindow::~ClothingItemsWindow()
{
    delete ui;
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

