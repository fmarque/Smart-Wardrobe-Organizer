#include "closetwindow.h"
#include "ui_closetwindow.h"

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

void ClosetWindow::on_pushButton_clicked()
{

}

