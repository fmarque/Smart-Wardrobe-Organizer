#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Start the application with the Login screen
    LoginWindow login;
    login.show();

    return a.exec();
}
