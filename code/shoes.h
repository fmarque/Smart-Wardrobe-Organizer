#ifndef SHOES_H
#define SHOES_H

#include "clothingitem.h"
#include <string>

class Shoes : public ClothingItem {
private:
    std::string colour;

public:
    // Constructor
    Shoes(const std::string &image, const std::string &clothingType, const std::string &colour);
    std::string getColour() const;
    void display() const override;  // override
};

#endif // SHOES_H
