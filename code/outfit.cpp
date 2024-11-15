#include <string>

class Outfit {
public:
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
    void Outfit::setTop(const std::string& top) {
        topName = top;
    }

    void Outfit::setBottom(const std::string& bottom) {
        bottomName = bottom;
    }

    void Outfit::setShoe(const std::string& shoe) {
        shoeName = shoe;
    }

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