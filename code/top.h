#ifndef TOP_H
#define TOP_H

#include "clothingitem.h"
#include <string>

class Top : public ClothingItem {
private:
    std::string colour;

public:
    // Constructor
    Top(const std::string &image, const std::string &clothingType, const std::string &colour);
    std::string getColour() const;
    void display() const override;  // override
};

#endif // TOP_H
