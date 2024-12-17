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



    std::list<ClothingItem*> tops;
    std::list<ClothingItem*> bottoms;
    std::list<ClothingItem*> shoes;
    std::list<ClothingItem*> coats;
    std::list<ClothingItem*> uploadedItems;
    std::list<Outfit> savedOutfits;
    QString clothingFilePath = QCoreApplication::applicationDirPath() + "../data/clothingItemsJSON.json";
    QString outfitFilePath = QCoreApplication::applicationDirPath() + "../data/savedOutfitsJSON.json";


    ClosetManager* ClosetManager::getInstance() {
    static ClosetManager instance;  // Singleton pattern
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
    }

    // // Upload Items to the 'clothing_pics' directory
    // void ClosetManager::uploadTest(const std::string& tempFilePath, const std::string& type) {
    //     // Get the directory for clothing_pics
    //     std::filesystem::path currentDir = std::filesystem::current_path();
    //     std::filesystem::path targetFolder = currentDir.parent_path().parent_path().parent_path() / "clothing_pics";

    //     // Ensure the directory exists
    //     if (!std::filesystem::exists(targetFolder)) {
    //         if (!std::filesystem::create_directory(targetFolder)) {
    //             std::cerr << "Failed to create directory: " << targetFolder << std::endl;
    //             return;
    //         }
    //     }

    //     // Generate unique file name
    //     int& count = typeCounts[type];
    //     std::filesystem::path targetPath;

    //     do {  // this is potentiallt the issue
    //         std::string uniqueFileName = type + "_" + std::to_string(++count) + ".png"; // Increment counter here
    //         targetPath = targetFolder / uniqueFileName;
    //     } while (std::filesystem::exists(targetPath)); // Ensure file doesn't already exist

    //     qDebug() << "Target path for renaming:" << QString::fromStdString(targetPath.string());



    //     // Attempt to move the file
    //     try {
    //         std::filesystem::rename(tempFilePath, targetPath);
    //         std::cout << "File has been uploaded to: " << targetPath << std::endl;

    //         addClothingItemToList(type, targetPath.string());
    //         printClothingItems();

    //     } catch (const std::filesystem::filesystem_error& e) {
    //         //std::cerr << "Failed to move file: " << e.what() << std::endl;
    //         return;
    //     }  // BUG: tries this twice

    //     // create an item object to store in JSON
    //     ClothingItem* newItem = nullptr;
    //     std::string colour = "unknown";   // Use a placeholder value or dynamically get the colour
    //     if (type == "top") {
    //         newItem = new Top(targetPath.string(), type, colour);  // Pass filePath, clothingType, and colour
    //         tops.push_back(newItem);
    //     } else if (type == "bottom") {
    //         newItem = new Bottom(targetPath.string(), type, colour);
    //         bottoms.push_back(newItem);
    //     } else if (type == "shoes") {
    //         newItem = new Shoes(targetPath.string(), type, colour);
    //         shoes.push_back(newItem);
    //     } else if (type == "coat") {
    //         newItem = new Coat(targetPath.string(), type, colour);
    //         coats.push_back(newItem);
    //     }

    //     // save item to JSON
    //     if (newItem) {
    //         saveClothingItemsToJSON(type, newItem->toJSON());
    //     } else {
    //         std::cerr << "Failed to create clothing item of type: " << type << std::endl;
    //     }

    // }



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
    std::string colour = "unknown";   // Use a placeholder value or dynamically get the colour

    // Create the appropriate clothing item based on 'type'
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

void ClosetManager::deleteClothingItemFromList(const std::string& imagePath) {
    std::string clothingType;


    // // Lambda to check if an item matches the image path
    // auto deleteCondition = [&imagePath](ClothingItem* item) {
    //     return item->getImage() == imagePath;
    // };


    // Lambda to check if an item matches the image path and determine the type
    auto deleteCondition = [&imagePath, &clothingType](ClothingItem* item) {
        if (item->getImage() == imagePath) {
            clothingType = item->getClothingType();
            return true;
        }
        return false;
    };


    // Remove from each list
    tops.remove_if(deleteCondition);
    bottoms.remove_if(deleteCondition);
    shoes.remove_if(deleteCondition);
    coats.remove_if(deleteCondition);
    uploadedItems.remove_if(deleteCondition);

    // remove deleted list item from JSON
     if (!clothingType.empty()) {
        removeClothingItemFromJSON(clothingType, imagePath);
        std::cout << "Item with image path " << imagePath << " has been removed from JSON." << std::endl;
    } else {
        std::cerr << "Clothing item with image path " << imagePath << " not found in lists." << std::endl;
    }


    std::cout << "Item with image path " << imagePath << " has been removed from all lists." << std::endl;

    // Get the current working directory
    std::filesystem::path currentPath = std::filesystem::current_path();

    // Go up four levels to get to the project root, then append "clothing_pics"
    std::filesystem::path clothingPicsDir = currentPath.parent_path().parent_path().parent_path().parent_path() / "clothing_pics"; 

    // Combine the clothing_pics directory with the image file name
    std::filesystem::path filePath = clothingPicsDir / imagePath;

    // Debug: Print the full file path being used
    std::cout << "Full file path: " << filePath << std::endl;

    // Attempt to delete the image file
    if (std::filesystem::exists(filePath)) {
        if (std::filesystem::remove(filePath)) {
            std::cout << "Image file " << imagePath << " has been deleted from clothing_pics." << std::endl;
        } else {
            std::cerr << "Failed to delete image file " << imagePath << "." << std::endl;
        }
    } else {
        std::cerr << "Image file " << imagePath << " not found in clothing_pics." << std::endl;
    }

    //TODO: remove from JSON helper method
}

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
            obj["imagePath"].toString().toStdString(),  // Use "imagePath"
            "top",
            obj["colour"].toString("unknown").toStdString()  // Default to "unknown" if "colour" is missing
        ));
    }

    // Repopulate `bottoms`
    QJsonArray bottomsArray = clothingData["bottoms"].toArray();
    for (const auto& item : bottomsArray) {
        QJsonObject obj = item.toObject();
        bottoms.push_back(new Bottom(
            obj["imagePath"].toString().toStdString(),  // Use "imagePath"
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

std::list<ClothingItem*> ClosetManager::getClothingItemsByType(const std::string& type) {
    if (type == "top") return tops;
    if (type == "bottom") return bottoms;
    if (type == "shoes") return shoes;
    if (type == "coat") return coats;
    return {};
}


    // // Load clothing items (implement loading from file or other source)
    // void loadItems() {
    //     // Load items logic
    // }

    // // Get the next item of a certain type
    // ClothingItem* getNextItem(const std::string& type) {
    //     // Implement logic to return the next item of the specified type
    //     return nullptr;
    // }

    // // Get the previous item of a certain type
    // ClothingItem* getPrevItem(const std::string& type) {
    //     // Implement logic to return the previous item of the specified type
    //     return nullptr;
    // }


    // // Upload a clothing item to the closet
    // void uploadItem(ClothingItem* item) {
    //     uploadedItems.push_back(item);
    // }

    // // Save a new outfit with just clothing names
    // void saveOutfit(std::string outfitName, std::string topName, std::string bottomName,
    //                 std::string shoeName = "", std::string coatName = "") {
    //     Outfit newOutfit(outfitName);

    //     newOutfit.setTop(topName);
    //     newOutfit.setBottom(bottomName);
    //     if (!shoeName.empty()) newOutfit.setShoe(shoeName);
    //     if (!coatName.empty()) newOutfit.setCoat(coatName);

    //     savedOutfits.push_back(newOutfit);
    // }

    // // Add a clothing item to the closet
    // void addClothingItem(std::string type, std::string name) {
    //     ClothingItem* item = new ClothingItem(name);

    //     if (type == "top") {
    //         tops.push_back(item);
    //     } else if (type == "bottom") {
    //         bottoms.push_back(item);
    //     } else if (type == "shoes") {
    //         shoes.push_back(item);
    //     } else if (type == "coat") {
    //         coats.push_back(item);
    //     }
    // }

//     // Get an outfit by name
//     Outfit loadOutfit(std::string name) {
//         for (auto& outfit : savedOutfits) {
//             if (outfit.getName() == name) {
//                 return outfit;
//             }
//         }
//         return Outfit(""); // Return an empty outfit if not found
//     }

//     // Rename an outfit
//     void renameOutfit(Outfit& outfit, const std::string& newName) {
//         outfit.setName(newName);
//     }

//     // Retrieve a clothing item by name from the closet lists
//     ClothingItem* getClothingItemByName(const std::string& name) {
//         // Check if the name matches an item in each list (tops, bottoms, shoes, coats)
//         for (auto& top : tops) {
//             if (top.getName() == name) return &top;
//         }
//         for (auto& bottom : bottoms) {
//             if (bottom.getName() == name) return &bottom;
//         }
//         for (auto& shoe : shoes) {
//             if (shoe.getName() == name) return &shoe;
//         }
//         for (auto& coat : coats) {
//             if (coat.getName() == name) return &coat;
//         }
//         return nullptr; // If not found
//     }

