#ifndef OUTFIT_H
#define OUTFIT_H

#include <string>
#include <QJsonObject>
#include <QJsonArray>

class Outfit {

public:
    std::string name;
    std::string topName;
    std::string bottomName;
    std::string shoeName;
    std::string coatName;

     Outfit(const std::string& name, const std::string& top, const std::string& bottom, const std::string& coat, const std::string& shoe);

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
    void setName(const std::string& newName);
    std::string getName() const;

};

#endif // OUTFIT_H
