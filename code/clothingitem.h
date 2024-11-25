#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include <string>
#include <vector>


class ClothingItem {
private:
    std::string image;
    std::string clothingType;
    std::vector<std::string> keywords;

public:
    // Constructor
    ClothingItem(const std::string &image, const std::string &clothingType);

    // Getter and setter for image
    std::string getImage() const;
    void setImage(const std::string &image);

    // Getter and setter for clothingType
    std::string getClothingType() const;
    void setClothingType(const std::string &clothingType);

    // // methods for keywords (MAY NOT USE ANYMORE)
    // std::vector<std::string> getKeywords() const;
    // void addKeyword(const std::string &keyword);

    // display method for testing
    void display() const;
};

#endif // CLOTHINGITEM_H
