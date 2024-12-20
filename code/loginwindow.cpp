#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainmenuwindow.h"
#include "global.h"
#include <QDebug>

QString userInput;  // Declare global variable

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QPushButton::clicked, this, &LoginWindow::onSaveButtonClicked);
}

// Destroyer
LoginWindow::~LoginWindow()
{
    delete ui;
}

// Save username entered upon click and open Main Menu after saving
void LoginWindow::onSaveButtonClicked()
{
    userInput = ui->lineEdit_3->text();
    MainMenu *mainMenu = new MainMenu(this);
    this->close();
    mainMenu->show();
}

