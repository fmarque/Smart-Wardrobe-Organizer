class Outfit {
public:
    std::string name;
    std::string topName;
    std::string bottomName;
    std::string shoeName;
    std::string coatName;

    Outfit(std::string name) : name(name) {}

    void setTop(std::string top) { topName = top; }
    void setBottom(std::string bottom) { bottomName = bottom; }
    void setShoe(std::string shoe) { shoeName = shoe; }
    void setCoat(std::string coat) { coatName = coat; }

    std::string getName() { return name; }
};