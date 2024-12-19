#ifndef CLOSETMANAGER_H
#define CLOSETMANAGER_H

#include "clothingitem.h"
#include "outfit.h"
#include <string>
#include <list>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <QCoreApplication>
#include <QDir>
#include "top.h"
#include "bottom.h"
#include "coat.h"
#include "shoes.h"
#include <memory>


class ClosetManager {
private:
    std::list<ClothingItem*> tops;
    std::list<ClothingItem*> bottoms;
    std::list<ClothingItem*> shoes;
    std::list<ClothingItem*> coats;
    std::list<ClothingItem*> uploadedItems;
    std::list<Outfit> savedOutfits;

    // Private constructor (if using Singleton pattern)
    ClosetManager();
    std::unordered_map<std::string, int> typeCounts;


public:
    // Singleton pattern, if used
    static ClosetManager* getInstance();

    std::list<ClothingItem*> getTops();
    std::list<ClothingItem*> getBottoms();
    std::list<ClothingItem*> getShoes();
    std::list<ClothingItem*> getCoats();

    void uploadTest(const std::string& filePath, const std::string& type);
    void loadOutfitFromJSON(const QString& clothingFilePath, const QString& outfitFilePath);
    void saveOutfitToJSON(const QString& clothingFilePath, const QString& outfitFilePath);
    void saveClothingItemsToJSON(const std::string& type, QJsonObject clothingItem);
    // Upload an item using a file path and type
    void removeClothingItemFromJSON(const std::string& type, const std::string& imagePath);

    void loadClothingItemsFromJSON();
    void uploadItem(const std::string& filePath, const std::string& type);

    void deleteClothingItemFromList(const std::string& imagePath);

    void printClothingItems();
    std::list<ClothingItem*> getClothingItemsByType(const std::string& type);


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

    // Add a clothing item to the closet
    void addClothingItemToList(const std::string& type, const std::string& filePath);

    // // Get an outfit by name
    // Outfit loadOutfit(const std::string& name);

    // // Rename an outfit
    // void renameOutfit(Outfit& outfit, const std::string& newName);

    // // Retrieve a clothing item by name from the closet lists
    // ClothingItem* getClothingItemByName(const std::string& name);

    // TODO: method to clear all files from disk memory
    // TODO: method to clear all items in all lists
};

#endif // CLOSETMANAGER_H
