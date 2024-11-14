#ifndef CLOSETWINDOW_H
#define CLOSETWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "ui_closetwindow.h"
#include "ui_popup1.h"

namespace Ui {
class ClosetWindow;
}

class ClosetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClosetWindow(QWidget *parent = nullptr);
    ~ClosetWindow();

private slots:
    void openFileDialog(const QString &buttonType); // Slot to open the file dialog with a button identifier

private:
    Ui::ClosetWindow *ui;

    QWidget *popUp;
};

#endif // CLOSETWINDOW_H
