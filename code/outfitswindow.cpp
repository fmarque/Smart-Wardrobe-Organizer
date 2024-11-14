#include "outfitswindow.h"
#include "ui_outfitswindow.h"

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
