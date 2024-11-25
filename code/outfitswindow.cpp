#include "outfitswindow.h"
#include "ui_outfitswindow.h"
#include "clothingitemswindow.h"  // Include here to define ClothingItemsWindow
#include "closetwindow.h"
#include "mainmenuwindow.h"
#include "loginWindow.h"
#include "global.h"


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

