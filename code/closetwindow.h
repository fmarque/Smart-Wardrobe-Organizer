#ifndef CLOSETWINDOW_H
#define CLOSETWINDOW_H

#include <QMainWindow>

namespace Ui {
class ClosetWindow;
}

class ClosetWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClosetWindow(QWidget *parent = nullptr);
    ~ClosetWindow();

private:
    Ui::ClosetWindow *ui;
};

#endif // CLOSETWINDOW_H
