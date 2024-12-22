#include "closetmanager.h"
#include "clothingitem.h"
#include "outfit.h"
#include "top.h"
#include "bottom.h"
#include "coat.h"
#include "shoes.h"
#include "jsonmanager.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <sstream>
#include <QDebug>
#include <QString>
#include <list>
#include <memory>
#include <QJsonObject>


    // Lists to hold each clothing item type
    std::list<ClothingItem*> tops;
    std::list<ClothingItem*> bottoms;
    std::list<ClothingItem*> shoes;
    std::list<ClothingItem*> coats;
    std::list<ClothingItem*> uploadedItems;
    std::list<Outfit> savedOutfits;

    QString clothingFilePath = QCoreApplication::applicationDirPath() + "../data/clothingItemsJSON.json";
    QString outfitFilePath = QCoreApplication::applicationDirPath() + "../data/savedOutfitsJSON.json";


    ClosetManager* ClosetManager::getInstance() {
    static ClosetManager instance;  // Singleton pattern instance
    return &instance;
    }

    ClosetManager::ClosetManager() {
        // Initialize the count for each clothing item - for naming purposes
        typeCounts = {
            {"top", 0},
            {"bottom", 0},
            {"shoe", 0},
            {"coat", 0}
        };

        // initialize JSON for clothing items
        JSONManager jsonManager;
        jsonManager.initializeClothingItemsJSON(clothingFilePath);
        loadClothingItemsFromJSON();
        qDebug() << "ITEMS LIST WITH LOAD CLOTHING UPON INIT";
        printClothingItems();
        qDebug() << "ClosetManager initialized and lists re-populated.";

        // initialize JSON for saved outfits
        jsonManager.initializeOutfitsJSON(outfitFilePath);
        loadOutfitsFromJSON();

         // Initialize empty coat and shoe to make them optional with an empty string and appropriate type
        ClothingItem* emptyCoat = new Coat("", "coat", "unknown");
        coats.push_back(emptyCoat);  // Add the empty coat to the list

        ClothingItem* emptyShoes = new Shoes("", "coat", "unknown");
        shoes.push_back(emptyShoes);  // Add the empty shoes to the list
    }
 
    // Getter for tops list 
    std::list<ClothingItem*> ClosetManager::getTops() {
        return tops;
    }

       // Getter for bottoms list
    std::list<ClothingItem*> ClosetManager::getBottoms() {
        return bottoms;
    }

    // Getter for shoes list 
    std::list<ClothingItem*> ClosetManager::getShoes() {
        return shoes;
    }

    // Getter for coats list 
    std::list<ClothingItem*> ClosetManager::getCoats() {
        return coats;
    }

void ClosetManager::uploadTest(const std::string& tempFilePath, const std::string& type) {
    // Get the target directory for clothing_pics
    std::filesystem::path targetFolder = std::filesystem::current_path().parent_path().parent_path().parent_path() / "clothing_pics";
    std::filesystem::create_directories(targetFolder);

    // Generate a unique file name
    int& count = typeCounts[type];
    std::filesystem::path targetPath;
    do {
        std::string uniqueFileName = type + "_" + std::to_string(++count) + ".png";
        targetPath = targetFolder / uniqueFileName;
    } while (std::filesystem::exists(targetPath));

    // Move the file to the target directory
    try {
        std::filesystem::rename(tempFilePath, targetPath);
        qDebug() << "File moved to:" << QString::fromStdString(targetPath.string());
    } catch (const std::filesystem::filesystem_error& e) {
        qDebug() << "Error moving file:" << e.what();
        return;
    }

    // Add the clothing item to the appropriate list and save to JSON
    addClothingItemToList(type, targetPath.string());
    printClothingItems();
    saveClothingItemsToJSON(type, QJsonObject{
        {"imagePath", QString::fromStdString(targetPath.string())},
        {"clothingType", QString::fromStdString(type)}
    });

    qDebug() << "Item uploaded and saved successfully!";
}



// Method to add clothingItem objects to list during runtime, must be called upon start and when updating.
void ClosetManager::addClothingItemToList(const std::string& type, const std::string& filePath) {
    ClothingItem* newItem = nullptr;
    std::string clothingType = type;  // Use the passed 'type' for clothingType
    std::string colour = "unknown";   // Use a placeholder value 

    // Create the appropriate clothing item based on type
    if (type == "top") {
        newItem = new Top(filePath, clothingType, colour);  // Pass filePath, clothingType, and colour
        tops.push_back(newItem);
    } else if (type == "bottom") {
        newItem = new Bottom(filePath, clothingType, colour);
        bottoms.push_back(newItem);
    } else if (type == "shoes") {
        newItem = new Shoes(filePath, clothingType, colour);
        shoes.push_back(newItem);
    } else if (type == "coat") {
        newItem = new Coat(filePath, clothingType, colour);
        coats.push_back(newItem);
    }

    // Add to the general list of uploaded items
    if (newItem) {
        uploadedItems.push_back(newItem);
        std::cout << "Successfully added " << type << " to the closet: " << filePath << std::endl;

    } else {
        std::cerr << "Unknown clothing type: " << type << std::endl;
    }
}

// Method to delete clothing clothing item
void ClosetManager::deleteClothingItemFromList(const std::string& imagePath) {
    std::string clothingType;

    // Lambda to find and delete the item in memory
    auto deleteCondition = [&imagePath, &clothingType](ClothingItem* item) {
        if (item->getImage() == imagePath) {
            clothingType = item->getClothingType();
            return true;
        }
        return false;
    };

    // Remove from lists
    tops.remove_if(deleteCondition);
    bottoms.remove_if(deleteCondition);
    shoes.remove_if(deleteCondition);
    coats.remove_if(deleteCondition);
    uploadedItems.remove_if(deleteCondition);

    // Remove the corresponding item from JSON
    if (!clothingType.empty()) {
        removeClothingItemFromJSON(clothingType, imagePath);
        qDebug() << "Item removed from JSON:" << QString::fromStdString(imagePath);
    } else {
        qDebug() << "Failed to find item with path:" << QString::fromStdString(imagePath);
    }

    // Attempt to delete the image file directly
    std::filesystem::path filePath = imagePath;  // Use the full path as provided
    qDebug() << "Attempting to delete file:" << QString::fromStdString(filePath.string());

    if (std::filesystem::exists(filePath)) {
        if (std::filesystem::remove(filePath)) {
            qDebug() << "File successfully deleted:" << QString::fromStdString(filePath.string());
        } else {
            qDebug() << "Failed to delete file:" << QString::fromStdString(filePath.string());
        }
    } else {
        qDebug() << "File not found for deletion:" << QString::fromStdString(filePath.string());
    }
}

// Method to save clothing items to JSON file
void ClosetManager::saveClothingItemsToJSON(const std::string& type, QJsonObject clothingItem) {
    JSONManager jsonManager;
    QString arrayKey;

    // Debug: Load existing data
    QJsonObject clothingData = jsonManager.load(clothingFilePath);
    qDebug() << "Loaded Clothing Data:" << QJsonDocument(clothingData).toJson();

    // Determine the correct array to add the item to
    if (type != "shoes") {
        arrayKey = QString::fromStdString(type) + "s"; // E.g., "tops", "bottoms"
    } else {
        arrayKey = "shoes";
    }
    QJsonArray itemsArray = clothingData[arrayKey].toArray();
    itemsArray.append(clothingItem);
    clothingData[arrayKey] = itemsArray;

    // Debug: Data before saving
    qDebug() << "Clothing Data Before Saving:" << QJsonDocument(clothingData).toJson();

    // Save the updated data back to the file
    jsonManager.save(clothingFilePath, clothingData);

    // Debug: Read the file to confirm changes
    QFile file(clothingFilePath);
    if (file.open(QIODevice::ReadOnly)) {
        qDebug() << "File Content After Saving:" << file.readAll();
        file.close();
    }
}

// Removes clothing item from JSON file
void ClosetManager::removeClothingItemFromJSON(const std::string& type, const std::string& imagePath) {
    JSONManager jsonManager;

    // Load the current JSON data
    QJsonObject clothingData = jsonManager.load(clothingFilePath);

    // Determine the correct array to remove the item from
    QString arrayKey = (type != "shoes") ? QString::fromStdString(type) + "s" : "shoes";
    QJsonArray itemsArray = clothingData[arrayKey].toArray();

    // Remove the item by matching the imagePath
    for (int i = 0; i < itemsArray.size(); ++i) {
        QJsonObject obj = itemsArray[i].toObject();
        if (obj["imagePath"].toString().toStdString() == imagePath) {
            itemsArray.removeAt(i);
            break;
        }
    }

    // Update the array in the JSON object
    clothingData[arrayKey] = itemsArray;

    // Save the updated JSON back to the file
    jsonManager.save(clothingFilePath, clothingData);

    // Debugging
    qDebug() << "Removed clothing item from JSON. Updated data:" << QJsonDocument(clothingData).toJson();
}

// Method to load clothing from JSON into list, can be used upon app opening or to refresh
void ClosetManager::loadClothingItemsFromJSON() {
    JSONManager jsonManager;
    QJsonObject clothingData = jsonManager.load(clothingFilePath);

    // Clear existing lists to avoid duplication
    tops.clear();
    bottoms.clear();
    shoes.clear();
    coats.clear();

    // Repopulate `tops`
    QJsonArray topsArray = clothingData["tops"].toArray();
    for (const auto& item : topsArray) {
        QJsonObject obj = item.toObject();
        tops.push_back(new Top(
            obj["imagePath"].toString().toStdString(),  
            "top",
            obj["colour"].toString("unknown").toStdString()  // Default to "unknown" if "colour" is missing
        ));
    }

    // Repopulate `bottoms`
    QJsonArray bottomsArray = clothingData["bottoms"].toArray();
    for (const auto& item : bottomsArray) {
        QJsonObject obj = item.toObject();
        bottoms.push_back(new Bottom(
            obj["imagePath"].toString().toStdString(), 
            "bottom",
            obj["colour"].toString("unknown").toStdString()
        ));
    }

    // Repopulate `shoes`
    QJsonArray shoesArray = clothingData["shoes"].toArray();
    for (const auto& item : shoesArray) {
        QJsonObject obj = item.toObject();
        shoes.push_back(new Shoes(
            obj["imagePath"].toString().toStdString(),
            "shoes",
            obj["colour"].toString("unknown").toStdString()
        ));
    }

    // Repopulate `coats`
    QJsonArray coatsArray = clothingData["coats"].toArray();
    for (const auto& item : coatsArray) {
        QJsonObject obj = item.toObject();
        coats.push_back(new Coat(
            obj["imagePath"].toString().toStdString(),
            "coat",
            obj["colour"].toString("unknown").toStdString()
        ));
    }

    qDebug() << "Clothing items loaded successfully from JSON.";
}

// Save an outfit to JSON
void ClosetManager::saveOutfitToJSON(const Outfit& outfit) {
    // Get object components of outfits
    // Make a general array of outfits
    // Populate the array with outfit items and paths

    // Load the existing data from the JSON file
    JSONManager jsonManager;
    QJsonObject outfitsData = jsonManager.load(outfitFilePath);

    // Get or create the "outfits" array
    QJsonArray outfitsArray = outfitsData["outfits"].toArray();

    // Create a JSON object for the new outfit
    QJsonObject outfitJson;
    outfitJson["name"] = QString::fromStdString(outfit.getName());
    outfitJson["coat"] = QString::fromStdString(outfit.getCoat());
    outfitJson["top"] = QString::fromStdString(outfit.getTop());
    outfitJson["bottom"] = QString::fromStdString(outfit.getBottom());
    outfitJson["shoes"] = QString::fromStdString(outfit.getShoe());

    // Add the outfit JSON object to the array
    outfitsArray.append(outfitJson);

    // Update the JSON object with the new array
    outfitsData["outfits"] = outfitsArray;

    // Save the updated JSON data back to the file
    jsonManager.save(outfitFilePath, outfitsData);

    qDebug() << "Outfit saved to JSON successfully:" << QJsonDocument(outfitJson).toJson();
}

// Load an outfit from JSON
void ClosetManager::loadOutfitsFromJSON() {
    // Initialize the JSON Manager
    JSONManager jsonManager;
    QJsonObject outfitsData = jsonManager.load(outfitFilePath);

    // Clear the savedOutfits list to avoid duplicates
    savedOutfits.clear();

    // Get the "outfits" array from the JSON object
    QJsonArray outfitsArray = outfitsData["outfits"].toArray();

    // Iterate through each object in the "outfits" array
    for (const QJsonValue& value : outfitsArray) {
        QJsonObject outfitJson = value.toObject();

        // Extract outfit properties
        std::string name = outfitJson["name"].toString().toStdString();
        std::string coat = outfitJson["coat"].toString().toStdString();
        std::string top = outfitJson["top"].toString().toStdString();
        std::string bottom = outfitJson["bottom"].toString().toStdString();
        std::string shoes = outfitJson["shoes"].toString().toStdString();

        // Create an Outfit object and add it to the savedOutfits list
        Outfit outfit(name, top, bottom, coat, shoes);
        savedOutfits.push_back(outfit);
    }

    qDebug() << "Outfits loaded successfully from JSON. Total outfits:" << savedOutfits.size();
}

// Method to remove outfit from the JSON file
void ClosetManager::removeOutfitFromJSON(const std::string& outfitName) {
    // Load the existing data from the JSON file
    JSONManager jsonManager;
    QJsonObject outfitsData = jsonManager.load(outfitFilePath);

    // Get the "outfits" array from the JSON file
    QJsonArray outfitsArray = outfitsData["outfits"].toArray();

    // Iterate through the array to find the outfit with the matching name
    for (int i = 0; i < outfitsArray.size(); ++i) {
        QJsonObject outfitJson = outfitsArray[i].toObject();
        if (outfitJson["name"].toString().toStdString() == outfitName) {
            // Remove the matching outfit from the array
            outfitsArray.removeAt(i);
            qDebug() << "Outfit removed from JSON: " << QString::fromStdString(outfitName);
            break; // Exit the loop once the outfit is found and removed
        }
    }

    // Update the JSON object with the modified array
    outfitsData["outfits"] = outfitsArray;

    // Save the updated JSON back to the file
    jsonManager.save(outfitFilePath, outfitsData);

    // Debugging output
    qDebug() << "Updated Outfits JSON Data: " << QJsonDocument(outfitsData).toJson();
}


void ClosetManager::printClothingItems() {
    // Print all tops
    std::cout << "Tops:" << std::endl;
    for (const auto& item : tops) {
        std::cout << "Image Path: " << item->getImage() << ", Type: " << item->getClothingType() << std::endl;
    }

    // Print all bottoms
    std::cout << "Bottoms:" << std::endl;
    for (const auto& item : bottoms) {
        std::cout << "Image Path: " << item->getImage() << ", Type: " << item->getClothingType() << std::endl;
    }

    // Print all shoes
    std::cout << "Shoes:" << std::endl;
    for (const auto& item : shoes) {
        std::cout << "Image Path: " << item->getImage() << ", Type: " << item->getClothingType() << std::endl;
    }

    // Print all coats
    std::cout << "Coats:" << std::endl;
    for (const auto& item : coats) {
        std::cout << "Image Path: " << item->getImage() << ", Type: " << item->getClothingType() << std::endl;
    }

    // Print all uploaded items
    std::cout << "Uploaded Items:" << std::endl;
    for (const auto& item : uploadedItems) {
        std::cout << "Image Path: " << item->getImage() << ", Type: " << item->getClothingType() << std::endl;
    }
}

// Retrieves clothing items by type
std::list<ClothingItem*> ClosetManager::getClothingItemsByType(const std::string& type) {
    if (type == "top") return tops;
    if (type == "bottom") return bottoms;
    if (type == "shoes") return shoes;
    if (type == "coat") return coats;
    return {};
}

// Save a new outfit to list
void ClosetManager::saveOutfit(const std::string& outfitName, const std::string& topName, 
                               const std::string& bottomName, const std::string& shoeName, 
                               const std::string& coatName) {
    // Call the constructor with all required arguments
    Outfit newOutfit(outfitName, topName, bottomName, coatName, shoeName);

    savedOutfits.push_back(newOutfit);  // Save the new outfit
    saveOutfitToJSON(newOutfit);
}

// Load an outfit by name from list
Outfit ClosetManager::loadOutfit(const std::string& name) const {
    for (const auto& outfit : savedOutfits) {
        if (outfit.getName() == name) {
            return outfit;  // Return the outfit if found
        }
    }
}

// Get a list of saved outfits
std::list<Outfit> ClosetManager::getSavedOutfits() const {
    return savedOutfits;
}

// Method to delete an outfit
void ClosetManager::removeOutfit(const std::string& outfitName) {
    // Lambda to find and delete the outfit based on one of its clothing items
    auto deleteCondition = [&outfitName](const Outfit& outfit) {
        if (outfit.getName() == outfitName) {
            return true;
        }
        return false;
    };

    // Remove from outfits list
    savedOutfits.remove_if(deleteCondition);
    removeOutfitFromJSON(outfitName);
}