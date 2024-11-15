#ifndef OUTFIT_H
#define OUTFIT_H

#include <string>

class Outfit {
public:
    std::string name;
    std::string topName;
    std::string bottomName;
    std::string shoeName;
    std::string coatName;

    // Constructor to initialize the outfit with a name
    Outfit(std::string name);

    // Setters for each clothing item
    void setTop(std::string top);
    void setBottom(std::string bottom);
    void setShoe(std::string shoe);
    void setCoat(std::string coat);

    // Getter for outfit name
    std::string getName();
};

#endif // OUTFIT_H
