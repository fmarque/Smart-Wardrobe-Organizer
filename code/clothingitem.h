#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

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
    ClothingItem(const std::string &image, const std::string &clothingType);

    // Getter and setter for image
    std::string getImage() const;
    void setImage(const std::string &image);

    // Getter and setter for clothingType
    std::string getClothingType() const;
    void setClothingType(const std::string &clothingType);

    // Display method for testing
    void display() const;

    QJsonObject toJSON() const;                // Convert ClothingItem to JSON
    static ClothingItem fromJSON(const QJsonObject &obj); // Create ClothingItem from JSON

};

#endif // CLOTHINGITEM_H
