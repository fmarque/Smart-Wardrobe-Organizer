#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include <string>
#include <vector>

// Declaration of the ClothingItem class
class ClothingItem {
private:
    std::string image;
    std::string clothingType;
    std::vector<std::string> keywords;

public:
    // constructor
    ClothingItem(const std::string &image, const std::string &clothingType);

    // getter and setter for image
    std::string getImage() const;
    void setImage(const std::string &image);

    // getter and setter for clothingType
    std::string getClothingType() const;
    void setClothingType(const std::string &clothingType);

    // methods for keywords
    std::vector<std::string> getKeywords() const;
    void addKeyword(const std::string &keyword);

    // display method
    void display() const;
};

#endif // CLOTHINGITEM_H
