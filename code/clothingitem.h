#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

// #include "top.h"
// #include "bottom.h"
// #include "coat.h"
// #include "shoes.h"
#include <string>
#include <vector>
#include <iostream>
#include <QJsonObject>
#include <QJsonArray>

class ClothingItem {
private:
    std::string image;
    std::string clothingType;
    std::vector<std::string> keywords; // Keywords may not be used.

public:
    // Constructor
    ClothingItem(const std::string& image, const std::string& clothingType);
    virtual ~ClothingItem() = default;
    // Getter and setter for image
    std::string getImage() const;
    void setImage(const std::string &image);

    // Getter and setter for clothingType
    std::string getClothingType() const;
    void setClothingType(const std::string &clothingType);

    // Display method for testing
    virtual void display() const = 0;

    // QJsonObject toJSON() const;                // Convert ClothingItem to JSON
    // static ClothingItem* fromJSON(const QJsonObject &obj); // Create ClothingItem from JSON
    virtual QJsonObject toJSON() const;
    static ClothingItem* fromJSON(const QJsonObject& obj); // Factory method

};

#endif // CLOTHINGITEM_H
