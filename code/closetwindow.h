#ifndef CLOSETWINDOW_H
#define CLOSETWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "ui_closetwindow.h"
#include "ui_popup1.h"
#include "croppingwindow.h"
#include "closetmanager.h"

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
    void on_pushButton_3_clicked();  // Slot for opening the Clothing Items window
    void on_pushButton_2_clicked();  // Slot for opening the Outfits window


    // Arrow button slots to navigate through clothing items
    void prevCoat();
    void nextCoat();
    void prevTop();
    void nextTop();
    void prevBottom();
    void nextBottom();
    void prevShoe();
    void nextShoe();

    void on_loadButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::ClosetWindow *ui;

    QWidget *popUp;

    // Indices to track the current clothing items
    int currentIndexCoat;
    int currentIndexTop;
    int currentIndexBottom;
    int currentIndexShoe;

    // keep track of current file path on screen
    QString currentTopImagePath;
    QString currentBottomImagePath;
    QString currentCoatImagePath;
    QString currentShoeImagePath;

    // Helper function to update the images on the labels
    void updateImageDisplay();

};

#endif // CLOSETWINDOW_H
