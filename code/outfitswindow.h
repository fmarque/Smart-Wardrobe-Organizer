#ifndef OUTFITSWINDOW_H
#define OUTFITSWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>
#include "clothingitemswindow.h"
#include "closetmanager.h"  // Include ClosetManager to access saved outfits


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
    void on_viewCloset_button_clicked();
    void on_backToMainMenu_button_clicked();

    void on_deleteOutfitButton_clicked();

    void populateOutfitDropdown();

private:
    Ui::OutfitsWindow *ui;
    void loadOutfits();  // Method to load outfits dynamically
};

#endif // OUTFITSWINDOW_H
