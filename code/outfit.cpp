#include "outfit.h"
#include "clothingitem.h"
#include <string>

    std::string name;
    std::string topName;
    std::string bottomName;
    std::string shoeName;
    std::string coatName;

    Outfit::Outfit(const std::string& name, const std::string& top, const std::string& bottom, const std::string& coat, const std::string& shoe)
    : name(name), topName(top), bottomName(bottom), shoeName(shoe), coatName(coat) {}


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
    std::string Outfit::getName() const { 
        return name; 
    }

    // Setter for outfit name
    void Outfit::setName(const std::string& newName) {
        name = newName;
    }

