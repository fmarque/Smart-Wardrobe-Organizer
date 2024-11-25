#include "bottom.h"
#include <iostream>

// Constructor
Bottom::Bottom(const std::string &image, const std::string &clothingType, const std::string &colour)
    : ClothingItem(image, clothingType), colour(colour) {}

// Getter for colour
std::string Bottom::getColour() const {
    return colour;
}

// Override display method
void Bottom::display() const {
    // In future, will check with JSON
    std::cout << "Bottom should match: " << getClothingType() << ", Colour: " << colour << "\n";
}
