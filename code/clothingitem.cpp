#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include <string>
#include <vector>
#include <iostream>

class ClothingItem {
private:
    std::string image;
    std::string clothingType;
    std::vector<std::string> keywords;

public:
    // constructor
    ClothingItem(const std::string &image, const std::string &clothingType)
        : image(image), clothingType(clothingType) {}

    // getters and setters
    std::string getImage() const {
        return image;
    }

    void setImage(const std::string &image) {
        this->image = image;
    }

    std::string getClothingType() const {
        return clothingType;
    }

    void setClothingType(const std::string &clothingType) {
        this->clothingType = clothingType;
    }

    std::vector<std::string> getKeywords() const {
        return keywords;
    }

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
