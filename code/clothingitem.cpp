#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include <string>
#include <vector>
#include <iostream>

class ClothingItem {
private:
    std::string image;
    std::string clothingType;
    std::vector<std::string> keywords;  // may not use this

public:
    // Constructor
    ClothingItem(const std::string &image, const std::string &clothingType)
        : image(image), clothingType(clothingType) {}

    // Get image
    std::string getImage() const {
        return image;
    }

    // Set clothing image
    void setImage(const std::string &image) {
        this->image = image;
    }

    // Get clothing type
    std::string getClothingType() const {
        return clothingType;
    }

    // Set clothing type
    void setClothingType(const std::string &clothingType) {
        this->clothingType = clothingType;
    }

    // display clothing item info (for testing purposes)
    void display() const {
        std::cout << "Clothing Type: " << clothingType << std::endl;
        std::cout << "Image Path: " << image << std::endl;
        std::cout << "Keywords: ";
        for (const auto &keyword : keywords) {
            std::cout << keyword << " ";
        }
        std::cout << std::endl;
    }
};

#endif // CLOTHINGITEM_H
