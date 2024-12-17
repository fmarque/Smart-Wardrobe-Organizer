#ifndef CLOTHINGITEMSWINDOW_H
#define CLOTHINGITEMSWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "closetwindow.h"
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

    void populateClothingItems(const std::string& type);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_uploadItem_button_clicked();

private:
    Ui::ClothingItemsWindow *ui;
    QWidget *popUp;  // Reuse pop-up for selecting clothing type
    void openFileDialog(const QString &buttonType);  // Shared logic
};

#endif // CLOTHINGITEMSWINDOW_H
