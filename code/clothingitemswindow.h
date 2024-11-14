#ifndef CLOTHINGITEMSWINDOW_H
#define CLOTHINGITEMSWINDOW_H

#include <QMainWindow>

namespace Ui {
class ClothingItemsWindow;
}

class ClothingItemsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClothingItemsWindow(QWidget *parent = nullptr);
    ~ClothingItemsWindow();

private:
    Ui::ClothingItemsWindow *ui;
};

#endif // CLOTHINGITEMSWINDOW_H
