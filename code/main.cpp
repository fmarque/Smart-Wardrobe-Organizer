#include "mainwindow.h"
#include "closetwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    ClosetWindow w;
    w.show();
    return a.exec();
}
