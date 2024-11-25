#ifndef CLOSETWINDOW_H
#define CLOSETWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "ui_closetwindow.h"
#include "ui_popup1.h"
#include "croppingwindow.h"

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
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::ClosetWindow *ui;

    QWidget *popUp;
};



#endif // CLOSETWINDOW_H
