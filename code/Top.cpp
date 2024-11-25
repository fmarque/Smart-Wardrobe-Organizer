#include "top.h"
#include "clothingItem.h"
#include <iostream>


class Top : public ClothingItem {
private:
    std::string colour; // Attribute specific to Top

public:
    // Constructor
    Top(const std::string &image, const std::string &clothingType, const std::string &colour)
        : ClothingItem(image, clothingType), colour(colour) {}

    // Destructor
    ~Top() {}

    // Getter for colour
    std::string getColour() const {
        return colour;
    }

    // Override display method
    void display() const {
        // in future, will check with json
        std::cout << "Top should match : " << getClothingType() << ", Colour: " << colour << "\n";
    }
};
