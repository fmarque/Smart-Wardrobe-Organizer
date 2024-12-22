#include "top.h"
#include <iostream>

// Constructor
Top::Top(const std::string &image, const std::string &clothingType, const std::string &colour)
    : ClothingItem(image, clothingType), colour(colour) {}

// Getter for colour
std::string Top::getColour() const {
    return colour;
}

// Override display method
void Top::display() const {
    std::cout << "Top should match: " << getClothingType() << ", Colour: " << colour << "\n";
}
