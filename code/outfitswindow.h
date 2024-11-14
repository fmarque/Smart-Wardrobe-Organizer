#ifndef OUTFITSWINDOW_H
#define OUTFITSWINDOW_H

#include <QMainWindow>
#include "clothingitemswindow.h"

namespace Ui {
class OutfitsWindow;
}

class OutfitsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OutfitsWindow(QWidget *parent = nullptr);
    ~OutfitsWindow();

private slots:
    void on_viewClothingItems_button_clicked();

private:
    Ui::OutfitsWindow *ui;
};

#endif // OUTFITSWINDOW_H
