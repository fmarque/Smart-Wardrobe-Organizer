#ifndef BOTTOM_H
#define BOTTOM_H

#include "clothingitem.h"
#include <string>

class Bottom : public ClothingItem {
private:
    std::string colour;

public:
    // Constructor
    Bottom(const std::string &image, const std::string &clothingType, const std::string &colour);
    std::string getColour() const;
    void display() const override;  // override
};

#endif // BOTTOM_H
