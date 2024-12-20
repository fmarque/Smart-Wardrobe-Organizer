#include "closetwindow.h"
#include "ui_closetwindow.h"
#include "ui_popup1.h"
#include <QFileDialog>
#include "clothingitemswindow.h"
#include "outfitswindow.h"
#include "closetmanager.h"

ClosetWindow::ClosetWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClosetWindow)
    , popUp(new QWidget(this)) // Initialize the pop-up as a child of ClosetWindow
{
    ui->setupUi(this);

    // Set up the pop-up widget using the generated PopUp1 UI
    Ui::popup1 popUpUi;
    popUpUi.setupUi(popUp);
    popUp->setWindowFlags(Qt::Popup); // Set it to behave like a pop-up

    // Connect the button in ClosetWindow to show the pop-up when clicked
    connect(ui->uploadButton, &QPushButton::clicked, [this]() {
        // Position the pop-up near the button when clicked
        QPoint pos = ui->uploadButton->mapToGlobal(QPoint(0, ui->uploadButton->height()));
        popUp->move(pos);
        popUp->show();
    });

    // Connect each button in the pop-up to openFileDialog with a different identifier
    connect(popUpUi.coatButton, &QPushButton::clicked, this, [this]() { openFileDialog("coat"); });
    connect(popUpUi.topButton, &QPushButton::clicked, this, [this]() { openFileDialog("top"); });
    connect(popUpUi.bottomButton, &QPushButton::clicked, this, [this]() { openFileDialog("bottom"); });
    connect(popUpUi.shoesButton, &QPushButton::clicked, this, [this]() { openFileDialog("shoes"); });

    // Initialize current indices for each clothing type
    currentIndexCoat = 0;
    currentIndexTop = 0;
    currentIndexBottom = 0;
    currentIndexShoe = 0;

    // Connect arrow button clicks to slot functions
    connect(ui->ArrowCoatPrev, &QPushButton::clicked, this, &ClosetWindow::prevCoat);
    connect(ui->ArrowCoatNext, &QPushButton::clicked, this, &ClosetWindow::nextCoat);
    connect(ui->ArrowTopPrev, &QPushButton::clicked, this, &ClosetWindow::prevTop);
    connect(ui->ArrowTopNext, &QPushButton::clicked, this, &ClosetWindow::nextTop);
    connect(ui->ArrowBottomPrev, &QPushButton::clicked, this, &ClosetWindow::prevBottom);
    connect(ui->ArrowBottomNext, &QPushButton::clicked, this, &ClosetWindow::nextBottom);
    connect(ui->ArrowShoesPrev, &QPushButton::clicked, this, &ClosetWindow::prevShoe);
    connect(ui->ArrowShoesNext, &QPushButton::clicked, this, &ClosetWindow::nextShoe);

    // Initialize the labels with the first clothing items
    updateImageDisplay();

    // initialize variables to keep track of filepaths of images on the screen
    QString currentTopImagePath;
    QString currentBottomImagePath;
    QString currentCoatImagePath;
    QString currentShoeImagePath;

}

// Destructor to clean up dynamically allocated memory
ClosetWindow::~ClosetWindow()
{
    delete ui;
    delete popUp;
}

// Opens the file dialog for image selection and processes the selected image
void ClosetWindow::openFileDialog(const QString &buttonType)
{
    // Open the file dialog and get the selected file path
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Images (*.png *.jpg *.jpeg)"));

    // Check if a file was selected
    if (!filePath.isEmpty()) {
        // Open the cropping window for image cropping
        CroppingWindow* cropWindow = new CroppingWindow(ClosetManager::getInstance(), filePath, buttonType, this);

        // Connect the cropped image signal to handle cropped image path
        connect(cropWindow, &CroppingWindow::imageCropped, this, [this, buttonType](const QString &croppedPath) {
            // Upload the cropped image and save metadata to the manager
            ClosetManager::getInstance()->uploadTest(croppedPath.toStdString(), buttonType.toStdString());
        });

        // Show the cropping window
        cropWindow->show();
    }
}

// Open the Clothing Items window upon click
void ClosetWindow::on_pushButton_3_clicked()
{
    this->hide();  // Hide the current window
    ClothingItemsWindow *CIWindow = new ClothingItemsWindow(this);
    CIWindow->show();  // Show the new window
}

// Open the Outfits window upon click
void ClosetWindow::on_pushButton_2_clicked()
{
    this->hide();  // Hide the current window
    OutfitsWindow *outfitsWindow = new OutfitsWindow(this);
    outfitsWindow->show();  // Show the new window
}


// Arrow button slots to navigate through clothing items
void ClosetWindow::prevCoat()
{
    // If the current index is 0, cycle to the last item in the list
    if (currentIndexCoat == 0)
    {
        currentIndexCoat = ClosetManager::getInstance()->getCoats().size() - 1;
    }
    else
    {
        currentIndexCoat--;
    }
    updateImageDisplay();
}

void ClosetWindow::nextCoat()
{
    // If the current index is the last item, cycle to the first item in the list
    if (currentIndexCoat == ClosetManager::getInstance()->getCoats().size() - 1)
    {
        currentIndexCoat = 0;
    }
    else
    {
        currentIndexCoat++;
    }
    updateImageDisplay();
}

void ClosetWindow::prevTop()
{
    // If the current index is 0, cycle to the last item in the list
    if (currentIndexTop == 0)
    {
        currentIndexTop = ClosetManager::getInstance()->getTops().size() - 1;
    }
    else
    {
        currentIndexTop--;
    }
    updateImageDisplay();
}

void ClosetWindow::nextTop()
{
    // If the current index is the last item, cycle to the first item in the list
    if (currentIndexTop == ClosetManager::getInstance()->getTops().size() - 1)
    {
        currentIndexTop = 0;
    }
    else
    {
        currentIndexTop++;
    }
    updateImageDisplay();
}

void ClosetWindow::prevBottom()
{
    // If the current index is 0, cycle to the last item in the list
    if (currentIndexBottom == 0)
    {
        currentIndexBottom = ClosetManager::getInstance()->getBottoms().size() - 1;
    }
    else
    {
        currentIndexBottom--;
    }
    updateImageDisplay();
}

void ClosetWindow::nextBottom()
{
    // If the current index is the last item, cycle to the first item in the list
    if (currentIndexBottom == ClosetManager::getInstance()->getBottoms().size() - 1)
    {
        currentIndexBottom = 0;
    }
    else
    {
        currentIndexBottom++;
    }
    updateImageDisplay();
}

void ClosetWindow::prevShoe()
{
    // If the current index is 0, cycle to the last item in the list
    if (currentIndexShoe == 0)
    {
        currentIndexShoe = ClosetManager::getInstance()->getShoes().size() - 1;
    }
    else
    {
        currentIndexShoe--;
    }
    updateImageDisplay();
}

void ClosetWindow::nextShoe()
{
    // If the current index is the last item, cycle to the first item in the list
    if (currentIndexShoe == ClosetManager::getInstance()->getShoes().size() - 1)
    {
        currentIndexShoe = 0;
    }
    else
    {
        currentIndexShoe++;
    }
    updateImageDisplay();
}


// Update the images displayed on the labels based on current indices
void ClosetWindow::updateImageDisplay()
{

    // Retrieve the clothing lists from ClosetManager
    auto coats = ClosetManager::getInstance()->getCoats();
    auto tops = ClosetManager::getInstance()->getTops();
    auto bottoms = ClosetManager::getInstance()->getBottoms();
    auto shoes = ClosetManager::getInstance()->getShoes();

    // Initialize file paths to empty
    currentTopImagePath.clear();
    currentBottomImagePath.clear();
    currentCoatImagePath.clear();
    currentShoeImagePath.clear();

    // Check for tops
    if (tops.empty()) {
        qDebug() << "Tops list is empty!";
        ui->label_top->clear(); // Clear the label if empty
    } else {
        auto topIt = std::next(tops.begin(), currentIndexTop);
        currentTopImagePath = QString::fromStdString((*topIt)->getImage());
        qDebug() << "Top Image Path:" << currentTopImagePath;
        if (currentTopImagePath.isEmpty()) {
            ui->label_top->clear(); // Clear the label if the file path is empty
        } else {
            ui->label_top->setPixmap(QPixmap(currentTopImagePath).scaled(ui->label_top->size(), Qt::KeepAspectRatio));
        }
    }

    // Check for bottoms
    if (bottoms.empty()) {
        qDebug() << "Bottoms list is empty!";
        ui->label_bottom->clear(); // Clear the label if empty
    } else {
        auto bottomIt = std::next(bottoms.begin(), currentIndexBottom);
        currentBottomImagePath = QString::fromStdString((*bottomIt)->getImage());
        qDebug() << "Bottom Image Path:" << currentBottomImagePath;
        if (currentBottomImagePath.isEmpty()) {
            ui->label_bottom->clear(); // Clear the label if the file path is empty
        } else {
            ui->label_bottom->setPixmap(QPixmap(currentBottomImagePath).scaled(ui->label_bottom->size(), Qt::KeepAspectRatio));
        }
    }

    // Check for coats
    if (coats.empty()) {
        qDebug() << "Coats list is empty!";
        ui->label_coat->clear(); // Clear the label if empty
    } else {
        auto coatIt = std::next(coats.begin(), currentIndexCoat);
        currentCoatImagePath = QString::fromStdString((*coatIt)->getImage());
        qDebug() << "Coat Image Path:" << currentCoatImagePath;
        if (currentCoatImagePath.isEmpty()) {
            ui->label_coat->clear(); // Clear the label if the file path is empty
        } else {
            ui->label_coat->setPixmap(QPixmap(currentCoatImagePath).scaled(ui->label_coat->size(), Qt::KeepAspectRatio));
        }
    }

    // Check for shoes
    if (shoes.empty()) {
        qDebug() << "Shoes list is empty!";
        ui->label_shoes->clear(); // Clear the label if empty
    } else {
        auto shoeIt = std::next(shoes.begin(), currentIndexShoe);
        currentShoeImagePath = QString::fromStdString((*shoeIt)->getImage());
        qDebug() << "Shoe Image Path:" << currentShoeImagePath;
        if (currentShoeImagePath.isEmpty()) {
            ui->label_shoes->clear(); // Clear the label if the file path is empty
        } else {
            ui->label_shoes->setPixmap(QPixmap(currentShoeImagePath).scaled(ui->label_shoes->size(), Qt::KeepAspectRatio));
        }
    }


}

void ClosetWindow::on_saveButton_clicked()
{
    bool ok;
    QString outfitName = QInputDialog::getText(this, "Save Outfit", "Enter outfit name:",
                                               QLineEdit::Normal, "", &ok);
    if (ok && !outfitName.isEmpty()) {
        // Save outfit using the current image paths
        ClosetManager::getInstance()->saveOutfit(outfitName.toStdString(),
                                                 currentTopImagePath.toStdString(),
                                                 currentBottomImagePath.toStdString(),
                                                 currentShoeImagePath.toStdString(),
                                                 currentCoatImagePath.toStdString());
        QMessageBox::information(this, "Success", "Outfit saved successfully!");
    } else {
        // If the user cancels or enters an empty name
        QMessageBox::warning(this, "Input Error", "Please enter a valid outfit name.");
    }
}


void ClosetWindow::on_loadButton_clicked()
{
    QStringList outfitNames;
    for (const auto& outfit : ClosetManager::getInstance()->getSavedOutfits()) {
        outfitNames.append(QString::fromStdString(outfit.getName()));
    }

    bool ok;
    QString selectedOutfit = QInputDialog::getItem(this, "Load Outfit", "Choose an outfit:",
                                                   outfitNames, 0, false, &ok);
    if (ok && !selectedOutfit.isEmpty()) {
        Outfit outfit = ClosetManager::getInstance()->loadOutfit(selectedOutfit.toStdString());

        // Initialize file paths to empty
        currentTopImagePath.clear();
        currentBottomImagePath.clear();
        currentCoatImagePath.clear();
        currentShoeImagePath.clear();

        // Check for top
        auto tops = ClosetManager::getInstance()->getTops();
        if (!tops.empty()) {
            currentTopImagePath = QString::fromStdString(outfit.getTop());
            if (currentTopImagePath.isEmpty()) {
                ui->label_top->clear(); // Clear if the file path is empty
            } else {
                ui->label_top->setPixmap(QPixmap(currentTopImagePath).scaled(ui->label_top->size(), Qt::KeepAspectRatio));
            }
        } else {
            ui->label_top->clear();
        }

        // Check for bottom
        auto bottoms = ClosetManager::getInstance()->getBottoms();
        if (!bottoms.empty()) {
            currentBottomImagePath = QString::fromStdString(outfit.getBottom());
            if (currentBottomImagePath.isEmpty()) {
                ui->label_bottom->clear(); // Clear if the file path is empty
            } else {
                ui->label_bottom->setPixmap(QPixmap(currentBottomImagePath).scaled(ui->label_bottom->size(), Qt::KeepAspectRatio));
            }
        } else {
            ui->label_bottom->clear();
        }

        // Check for coat
        auto coats = ClosetManager::getInstance()->getCoats();
        if (!coats.empty()) {
            currentCoatImagePath = QString::fromStdString(outfit.getCoat());
            if (currentCoatImagePath.isEmpty()) {
                ui->label_coat->clear(); // Clear if the file path is empty
            } else {
                ui->label_coat->setPixmap(QPixmap(currentCoatImagePath).scaled(ui->label_coat->size(), Qt::KeepAspectRatio));
            }
        } else {
            ui->label_coat->clear();
        }

        // Check for shoes
        auto shoes = ClosetManager::getInstance()->getShoes();
        if (!shoes.empty()) {
            currentShoeImagePath = QString::fromStdString(outfit.getShoe());
            if (currentShoeImagePath.isEmpty()) {
                ui->label_shoes->clear(); // Clear if the file path is empty
            } else {
                ui->label_shoes->setPixmap(QPixmap(currentShoeImagePath).scaled(ui->label_shoes->size(), Qt::KeepAspectRatio));
            }
        } else {
            ui->label_shoes->clear();
        }
    }
}
