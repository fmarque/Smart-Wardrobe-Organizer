#include "clothingitem.h"
#include <iostream>

// Constructor
ClothingItem::ClothingItem(const std::string &image, const std::string &clothingType)
    : image(image), clothingType(clothingType) {}

// Getter and setter for image
std::string ClothingItem::getImage() const {
    return image;
}

void ClothingItem::setImage(const std::string &image) {
    this->image = image;
}

// Getter and setter for clothingType
std::string ClothingItem::getClothingType() const {
    return clothingType;
}

void ClothingItem::setClothingType(const std::string &clothingType) {
    this->clothingType = clothingType;
}

// Display method for testing
void ClothingItem::display() const {
    std::cout << "Clothing Type: " << clothingType << std::endl;
    std::cout << "Image Path: " << image << std::endl;
    std::cout << "Keywords: ";
    for (const auto &keyword : keywords) {
        std::cout << keyword << " ";
    }
    std::cout << std::endl;
}

// JSON Serialization
QJsonObject ClothingItem::toJSON() const {
    QJsonObject obj;
    obj["image"] = QString::fromStdString(image);
    obj["clothingType"] = QString::fromStdString(clothingType);

    // Optional: Serialize keywords if needed
    QJsonArray keywordsArray;
    for (const auto &keyword : keywords) {
        keywordsArray.append(QString::fromStdString(keyword));
    }
    obj["keywords"] = keywordsArray;

    return obj;
}

ClothingItem ClothingItem::fromJSON(const QJsonObject &obj) {
    ClothingItem item(
        obj["image"].toString().toStdString(),
        obj["clothingType"].toString().toStdString()
    );

    // Optional: Deserialize keywords if needed
    if (obj.contains("keywords")) {
        QJsonArray keywordsArray = obj["keywords"].toArray();
        for (const auto &keyword : keywordsArray) {
            item.keywords.push_back(keyword.toString().toStdString());
        }
    }

    return item;
}
