#include "clothingitem.h"
#include "top.h"
#include "bottom.h"
#include "coat.h"
#include "shoes.h"
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
    obj["imagePath"] = QString::fromStdString(image);
    obj["clothingType"] = QString::fromStdString(clothingType);
    return obj;
}

ClothingItem* ClothingItem::fromJSON(const QJsonObject& obj) {
    std::string image = obj["image"].toString().toStdString();
    std::string clothingType = obj["clothingType"].toString().toStdString();

    // Factory logic to create the appropriate subclass
    if (clothingType == "top") {
        std::string colour = obj["colour"].toString().toStdString();
        return new Top(image, clothingType, colour);
    } else if (clothingType == "bottom") {
        std::string colour = obj["colour"].toString().toStdString();
        return new Bottom(image, clothingType, colour);
    } else if (clothingType == "shoe") {
        std::string colour = obj["colour"].toString().toStdString();
        return new Shoes(image, clothingType, colour);
    } else if (clothingType == "coat") {
        std::string colour = obj["colour"].toString().toStdString();
        return new Coat(image, clothingType, colour);
    }

    // Default to nullptr if the type is unknown
    return nullptr;
}

