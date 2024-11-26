#include "shoes.h"
#include <iostream>

// Constructor
Shoes::Shoes(const std::string &image, const std::string &clothingType, const std::string &colour)
    : ClothingItem(image, clothingType), colour(colour) {}

// Getter for colour
std::string Shoes::getColour() const {
    return colour;
}

// Override display method
void Shoes::display() const {
    // In future, will check with JSON
    std::cout << "Shoes should match: " << getClothingType() << ", Colour: " << colour << "\n";
}
