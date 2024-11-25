#include <string>

class Outfit {
public:
    // Stores file string name for the outfit as well as the file name of each clothing item
    std::string name;
    std::string topName;
    std::string bottomName;
    std::string shoeName;
    std::string coatName;

    Outfit::Outfit(const std::string& name) : name(name) {}

    // Getters
    std::string Outfit::getTop() const { 
        return topName; 
    }

    std::string Outfit::getBottom() const {
        return bottomName; 
    }

    std::string Outfit::getShoe() const {
        return shoeName; 
    }

    std::string Outfit::getCoat() const {
        return coatName;
    }

    // Setters
    // Set top for outfit
    void Outfit::setTop(const std::string& top) {
        topName = top;
    }

    // Set outfit bottom
    void Outfit::setBottom(const std::string& bottom) {
        bottomName = bottom;
    }

    // Set outfit shoe
    void Outfit::setShoe(const std::string& shoe) {
        shoeName = shoe;
    }

    // Set outfit coat
    void Outfit::setCoat(const std::string& coat) {
        coatName = coat;
    }

    // Getter for outfit name
    std::string Outfit::getName() { 
        return name; 
    }

    // Setter for outfit name
    void Outfit::setName(const std::string& newName) {
        name = newName;
    }
    
};