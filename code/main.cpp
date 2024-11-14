#include "mainwindow.h"
#include "loginwindow.h"
#include "clothingitemswindow.h" // testing
#include "outfitswindow.h"
#include "closetwindow.h"
#include "mainmenuwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainMenu menu;
    LoginWindow login;
    //login.show();
    menu.show();
    //w.show();
    //ClothingItemsWindow items;
    //items.show();
    return a.exec();
}
