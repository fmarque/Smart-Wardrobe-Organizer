#ifndef CLOTHINGITEMSWINDOW_H
#define CLOTHINGITEMSWINDOW_H

#include <QMainWindow>
#include "outfitswindow.h"
//#include "clothingitemswindow.h"

namespace Ui {
class ClothingItemsWindow;
}

class ClothingItemsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClothingItemsWindow(QWidget *parent = nullptr);
    ~ClothingItemsWindow();

private slots:
    void on_viewClothingItems_button_clicked();

    void on_viewCloset_button_clicked();

    void on_backToMainMeny_button_clicked();

private:
    Ui::ClothingItemsWindow *ui;
};

#endif // CLOTHINGITEMSWINDOW_H
