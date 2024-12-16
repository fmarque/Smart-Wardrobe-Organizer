#include "loginwindow.h"
#include "closetmanager.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // initialize closet manager at startup
    ClosetManager* manager = ClosetManager::getInstance();
    qDebug() << "ClosetManager initialized at application startup.";

    // Start the application with the Login screen
    LoginWindow login;
    login.show();

    return a.exec();
}
