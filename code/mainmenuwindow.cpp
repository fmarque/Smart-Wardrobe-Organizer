#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"
#include "closetwindow.h"
#include "outfitswindow.h"
#include "clothingitemswindow.h"
#include "loginwindow.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_pushButton_clicked()
{
    this->hide();  // Hide the current window
    ClosetWindow *closetWindow = new ClosetWindow(this);  // Create a new ClothingItemsWindow
    closetWindow->show();  // Show the new window
}


void MainMenu::on_pushButton_2_clicked()
{
    this->hide();  // Hide the current window
    OutfitsWindow *outfitsWindow = new OutfitsWindow(this);  // Create a new ClothingItemsWindow
    outfitsWindow->show();  // Show the new window
}


void MainMenu::on_pushButton_3_clicked()
{
    this->hide();  // Hide the current window
    ClothingItemsWindow *clothingItemsWindow = new ClothingItemsWindow(this);  // Create a new ClothingItemsWindow
    clothingItemsWindow->show();  // Show the new window
}


void MainMenu::on_pushButton_7_clicked()
{
    this->hide();  // Hide the current window
    LoginWindow *loginWindow = new LoginWindow(this);  // Create a new ClothingItemsWindow
    loginWindow->show();  // Show the new window
}

