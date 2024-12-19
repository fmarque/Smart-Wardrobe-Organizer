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

        // Check if any list is empty
        if (tops.empty()) {
            qDebug() << "Tops list is empty!";
            ui->label_top->clear(); // Clear the label if empty
        } else {
            // Access the current clothing item from tops
            auto topIt = std::next(tops.begin(), currentIndexTop);
            qDebug() << "Top Image Path:" << (*topIt)->getImage().c_str();
            ui->label_top->setPixmap(QPixmap(QString::fromStdString((*topIt)->getImage())).scaled(ui->label_top->size(), Qt::KeepAspectRatio));
        }

        if (bottoms.empty()) {
            qDebug() << "Bottoms list is empty!";
            ui->label_bottom->clear(); // Clear the label if empty
        } else {
            // Access the current clothing item from bottoms
            auto bottomIt = std::next(bottoms.begin(), currentIndexBottom);
            qDebug() << "Bottom Image Path:" << (*bottomIt)->getImage().c_str();
            ui->label_bottom->setPixmap(QPixmap(QString::fromStdString((*bottomIt)->getImage())).scaled(ui->label_bottom->size(), Qt::KeepAspectRatio));
        }

        if (coats.empty()) {
            qDebug() << "Coats list is empty!";
            ui->label_coat->clear(); // Clear the label if empty
        } else {
            // Access the current clothing item from coats
            auto coatIt = std::next(coats.begin(), currentIndexCoat);
            qDebug() << "Coat Image Path:" << (*coatIt)->getImage().c_str();
            ui->label_coat->setPixmap(QPixmap(QString::fromStdString((*coatIt)->getImage())).scaled(ui->label_coat->size(), Qt::KeepAspectRatio));
        }

        if (shoes.empty()) {
            qDebug() << "Shoes list is empty!";
            ui->label_shoes->clear(); // Clear the label if empty
        } else {
            // Access the current clothing item from shoes
            auto shoeIt = std::next(shoes.begin(), currentIndexShoe);
            qDebug() << "Shoe Image Path:" << (*shoeIt)->getImage().c_str();
            ui->label_shoes->setPixmap(QPixmap(QString::fromStdString((*shoeIt)->getImage())).scaled(ui->label_shoes->size(), Qt::KeepAspectRatio));
        }


}
