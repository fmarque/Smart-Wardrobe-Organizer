#ifndef TOP_H
#define TOP_H

#include "clothingitem.h"
#include <string>

class Top : public ClothingItem {
private:
    std::string colour;

public:
    Top(const std::string &image, const std::string &clothingType, const std::string &colour);
    ~Top();
    std::string getColour() const;
    void display() const;
};

#endif // TOP_H
