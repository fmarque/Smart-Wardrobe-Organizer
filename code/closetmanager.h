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

    void loadOutfitsFromJSON();
    void saveOutfitToJSON(const Outfit& outfit);  // if buggy, try removing the &
    void removeOutfitFromJSON(const std::string& outfitName);

    void saveClothingItemsToJSON(const std::string& type, QJsonObject clothingItem);
    void removeClothingItemFromJSON(const std::string& type, const std::string& imagePath);
    void loadClothingItemsFromJSON();


    void uploadItem(const std::string& filePath, const std::string& type);
    void deleteClothingItemFromList(const std::string& imagePath);
    void printClothingItems();
    std::list<ClothingItem*> getClothingItemsByType(const std::string& type);
    void saveOutfit(const std::string& outfitName, const std::string& topName, 
                               const std::string& bottomName, const std::string& shoeName, 
                               const std::string& coatName);

    Outfit loadOutfit(const std::string& name) const;
    std::list<Outfit> getSavedOutfits() const;
    void removeOutfit(const std::string& outfitName);

    // Add a clothing item to the closet
    void addClothingItemToList(const std::string& type, const std::string& filePath);

};

#endif // CLOSETMANAGER_H
