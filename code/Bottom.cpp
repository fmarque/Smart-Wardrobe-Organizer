#include "clothingItem.h"
#include <iostream>


class Bottom : public ClothingItem {
private:
    std::string colour; // Attribute specific to Top

public:
    // Constructor
    Bottom(const std::string &image, const std::string &clothingType, const std::string &colour)
        : ClothingItem(image, clothingType), colour(colour) {}

    // Destructor
    ~Bottom() {}

    // Getter for colour
    std::string getColour() const {
        return colour;
    }

    // Override display method
    void display() const {
        // in future, will check with json
        std::cout << "Bottom should match : " << getClothingType() << ", Colour: " << colour << "\n";
    }
};
