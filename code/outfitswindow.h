#ifndef OUTFITSWINDOW_H
#define OUTFITSWINDOW_H

#include <QMainWindow>

namespace Ui {
class OutfitsWindow;
}

class OutfitsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OutfitsWindow(QWidget *parent = nullptr);
    ~OutfitsWindow();

private:
    Ui::OutfitsWindow *ui;
};

#endif // OUTFITSWINDOW_H
