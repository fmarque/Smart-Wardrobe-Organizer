#ifndef CLOSETMANAGER_H
#define CLOSETMANAGER_H

#include "clothingitem.h"
#include "outfit.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>

class ClosetManager {
private:
    // std::vector<Top> tops;
    // std::vector<Bottom> bottoms;
    // std::vector<Shoe> shoes;
    // std::vector<Coat> coats;
    // std::vector<ClothingItem*> uploadedItems;  // Will store all ClothingItems (Top, Bottom, Shoe, etc.)
    // std::vector<Outfit> savedOutfits;
    // Private constructor (if using Singleton pattern)
    ClosetManager();
    std::unordered_map<std::string, int> typeCounts;


public:
    // Singleton pattern, if used
    static ClosetManager* getInstance();

    void uploadTest(const std::string& filePath, const std::string& type);
    void saveMetadata(const std::string &imagePath, const std::string &type);

    // // Upload an item using a file path and type
    // void uploadItem(const std::string& filePath, const std::string& type);

    // // Load clothing items (implement loading from file or other source)
    // void loadItems();

    // // Get the next item of a certain type
    // ClothingItem* getNextItem(const std::string& type);

    // // Get the previous item of a certain type
    // ClothingItem* getPrevItem(const std::string& type);

    // // Upload a clothing item to the closet
    // void uploadItem(ClothingItem* item);

    // // Save a new outfit with just clothing names
    // void saveOutfit(const std::string& outfitName, const std::string& topName,
    //                 const std::string& bottomName, const std::string& shoeName = "",
    //                 const std::string& coatName = "");

    // // Add a clothing item to the closet
    // void addClothingItem(const std::string& type, const std::string& name);

    // // Get an outfit by name
    // Outfit loadOutfit(const std::string& name);

    // // Rename an outfit
    // void renameOutfit(Outfit& outfit, const std::string& newName);

    // // Retrieve a clothing item by name from the closet lists
    // ClothingItem* getClothingItemByName(const std::string& name);
};

#endif // CLOSETMANAGER_H
