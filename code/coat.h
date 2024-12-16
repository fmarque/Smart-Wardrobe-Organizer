#ifndef COAT_H
#define COAT_H

#include "clothingitem.h"
#include <string>

class Coat : public ClothingItem {
private:
    std::string colour;

public:
    // Constructor
    Coat(const std::string &image, const std::string &clothingType, const std::string &colour);
    std::string getColour() const;
    void display() const override;  // override
};

#endif // COAT_H
