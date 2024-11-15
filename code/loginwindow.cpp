#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainmenuwindow.h"
#include "global.h"

QString userInput;

#include <QDebug>


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    // setup set username functionality
    connect(ui->saveButton, &QPushButton::clicked, this, &LoginWindow::onSaveButtonClicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::onSaveButtonClicked()
{
    userInput = ui->lineEdit_3->text();
    MainMenu *mainMenu = new MainMenu(this);
    this->close();
    mainMenu->show();
    //qDebug() << "Username saved:" << userInput;

}
