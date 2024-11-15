#ifndef OUTFIT_H
#define OUTFIT_H

#include <string>

class Outfit {
public:
    // Constructor
    Outfit(const std::string& name);

    // Getters
    std::string getTop() const;
    std::string getBottom() const;
    std::string getShoe() const;
    std::string getCoat() const;
    
    // Setters
    void setTop(const std::string& top);
    void setBottom(const std::string& bottom);
    void setShoe(const std::string& shoe);
    void setCoat(const std::string& coat);

    // Name getter and setter
    std::string getName() const;

    void setName(const std::string& newName);


private:
    std::string name;
    std::string topName;
    std::string bottomName;
    std::string shoeName;
    std::string coatName;
};


#endif // OUTFIT_H
