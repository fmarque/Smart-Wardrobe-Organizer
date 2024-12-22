#include "coat.h"
#include <iostream>

// Constructor
Coat::Coat(const std::string &image, const std::string &clothingType, const std::string &colour)
    : ClothingItem(image, clothingType), colour(colour) {}

// Getter for colour
std::string Coat::getColour() const {
    return colour;
}

// Override display method
void Coat::display() const {
    std::cout << "Coat should match: " << getClothingType() << ", Colour: " << colour << "\n";
}
