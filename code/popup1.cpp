#include "popup1.h"
#include "ui_popup1.h"

popup1::popup1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::popup1)
{
    ui->setupUi(this);
}

popup1::~popup1()
{
    delete ui;
}
