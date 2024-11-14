#include "mainwindow.h"
#include "loginwindow.h"
#include "clothingitemswindow.h" // testing
#include "outfitswindow.h"
#include "closetwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    // LoginWindow login;
    // login.show();
    //w.show();
    //ClothingItemsWindow items;
    //items.show();
    ClosetWindow closet;
    closet.show();
    return a.exec();
}
