#include "clothingitem.h"
class ClosetManager {
private:
    std::vector<Top> tops;
    std::vector<Bottom> bottoms;
    std::vector<Shoe> shoes;
    std::vector<Coat> coats;
    std::vector<ClothingItem*> uploadedItems;  // Will store all ClothingItems (Top, Bottom, Shoe, etc.)
    std::vector<Outfit> savedOutfits;

public:
    // Load clothing items (implement loading from file or other source)
    void loadItems() {
        // Load items logic
    }

    // Get the next item of a certain type
    ClothingItem* getNextItem(const std::string& type) {
        // Implement logic to return the next item of the specified type
        return nullptr;
    }

    // Get the previous item of a certain type
    ClothingItem* getPrevItem(const std::string& type) {
        // Implement logic to return the previous item of the specified type
        return nullptr;
    }


    // Upload a clothing item to the closet
    void uploadItem(ClothingItem* item) {
        uploadedItems.push_back(item);
    }

    // Save a new outfit with just clothing names
    void saveOutfit(std::string outfitName, std::string topName, std::string bottomName,
                    std::string shoeName = "", std::string coatName = "") {
        Outfit newOutfit(outfitName);

        newOutfit.setTop(topName);
        newOutfit.setBottom(bottomName);
        if (!shoeName.empty()) newOutfit.setShoe(shoeName);
        if (!coatName.empty()) newOutfit.setCoat(coatName);

        savedOutfits.push_back(newOutfit);
    }

    // Add a clothing item to the closet
    void addClothingItem(std::string type, std::string name) {
        ClothingItem* item = new ClothingItem(name);

        if (type == "top") {
            tops.push_back(item);
        } else if (type == "bottom") {
            bottoms.push_back(item);
        } else if (type == "shoes") {
            shoes.push_back(item);
        } else if (type == "coat") {
            coats.push_back(item);
        }
    }

    // Get an outfit by name
    Outfit loadOutfit(std::string name) {
        for (auto& outfit : savedOutfits) {
            if (outfit.getName() == name) {
                return outfit;
            }
        }
        return Outfit(""); // Return an empty outfit if not found
    }

    // Rename an outfit
    void renameOutfit(Outfit& outfit, const std::string& newName) {
        outfit.setName(newName);
    }

    // Retrieve a clothing item by name from the closet lists
    ClothingItem* getClothingItemByName(const std::string& name) {
        // Check if the name matches an item in each list (tops, bottoms, shoes, coats)
        for (auto& top : tops) {
            if (top.getName() == name) return &top;
        }
        for (auto& bottom : bottoms) {
            if (bottom.getName() == name) return &bottom;
        }
        for (auto& shoe : shoes) {
            if (shoe.getName() == name) return &shoe;
        }
        for (auto& coat : coats) {
            if (coat.getName() == name) return &coat;
        }
        return nullptr; // If not found
    }
};
