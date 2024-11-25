#ifndef SHOES_H
#define SHOES_H

#include "clothingitem.h"
#include <string>

class Shoes : public ClothingItem {
private:
    std::string colour;

public:
    Shoes(const std::string &image, const std::string &clothingType, const std::string &colour);
    ~Shoes();
    std::string getColour() const;
    void display() const;
};

#endif // SHOES_H
