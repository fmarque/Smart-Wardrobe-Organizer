#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"
#include "closetwindow.h"
#include "outfitswindow.h"
#include "clothingitemswindow.h"
#include "loginwindow.h"
#include "global.h"


MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)

{
    ui->setupUi(this);
    ui->closetLabel->setText("Welcome to your virtual closet, " + userInput + "!");
}

// Destroyer
MainMenu::~MainMenu()
{
    delete ui;
}

// Open the Closet window upon click
void MainMenu::on_pushButton_clicked()
{
    this->hide();  // Hide the current window
    ClosetWindow *closetWindow = new ClosetWindow(this); 
    closetWindow->show();  // Show the new window
}

// Open the Outfits window upon click
void MainMenu::on_pushButton_2_clicked()
{
    this->hide();  // Hide the current window
    OutfitsWindow *outfitsWindow = new OutfitsWindow(this);
    outfitsWindow->show();  // Show the new window
}

// Open the Clothing Items window upon click
void MainMenu::on_pushButton_3_clicked()
{
    this->hide();  // Hide the current window
    ClothingItemsWindow *clothingItemsWindow = new ClothingItemsWindow(this);
    clothingItemsWindow->show();  // Show the new window
}

// Open the Login window upon click
void MainMenu::on_pushButton_7_clicked()
{
    this->hide();  // Hide the current window
    LoginWindow *loginWindow = new LoginWindow(this);
    loginWindow->show();  // Show the new window
}

