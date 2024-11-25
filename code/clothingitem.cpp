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
