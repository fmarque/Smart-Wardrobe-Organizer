#include "closetmanager.h"
#include "clothingitem.h"
#include "outfit.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <sstream>
#include <QDebug>
#include <QString>



    // std::vector<Top> tops;
    // std::vector<Bottom> bottoms;
    // std::vector<Shoe> shoes;
    // std::vector<Coat> coats;
    // std::vector<ClothingItem*> uploadedItems;  // Will store all ClothingItems (Top, Bottom, Shoe, etc.)
    // std::vector<Outfit> savedOutfits;

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
    }

    // Upload Items to the 'clothing_pics' directory
    void ClosetManager::uploadTest(const std::string& tempFilePath, const std::string& type) {
        // Get the directory for clothing_pics
        std::filesystem::path currentDir = std::filesystem::current_path();
        std::filesystem::path targetFolder = currentDir.parent_path().parent_path().parent_path() / "clothing_pics";

        // Ensure the directory exists
        if (!std::filesystem::exists(targetFolder)) {
            if (!std::filesystem::create_directory(targetFolder)) {
                std::cerr << "Failed to create directory: " << targetFolder << std::endl;
                return;
            }
        }

        // Generate unique file name
        int& count = typeCounts[type];
        std::filesystem::path targetPath;

        do {  // this is potentiallt the issue
            std::string uniqueFileName = type + "_" + std::to_string(++count) + ".png"; // Increment counter here
            targetPath = targetFolder / uniqueFileName;
        } while (std::filesystem::exists(targetPath)); // Ensure file doesn't already exist

        qDebug() << "Target path for renaming:" << QString::fromStdString(targetPath.string());



        // Attempt to move the file
        try {
            std::filesystem::rename(tempFilePath, targetPath);
            std::cout << "File has been uploaded to: " << targetPath << std::endl;
        } catch (const std::filesystem::filesystem_error& e) {
            //std::cerr << "Failed to move file: " << e.what() << std::endl;
            return;
        }  // BUG: tries this twice

        // Save metadata
        saveMetadata(targetPath.string(), type);
    }




    void ClosetManager::saveMetadata(const std::string &imagePath, const std::string &type) {
        // Example: Save metadata to a JSON file or database
        std::cout << "Metadata saved: " << imagePath << " (" << type << ")" << std::endl;
    }



//     // upload test to see if front end sends image to backend
//    void ClosetManager::uploadTest(const std::string &filePath) {
//         // Get the current working directory (where the executable is running)
//         std::filesystem::path currentDir = std::filesystem::current_path();

//         // Navigate up to the 'code' directory (two levels up)
//         std::filesystem::path targetFolder = currentDir.parent_path().parent_path().parent_path().parent_path() / "clothing_pics";

//         // Debug: Print the target folder to verify
//         std::cout << "Target folder: " << targetFolder << std::endl;

//         // Check if the directory exists, create it if it doesn't
//         if (!std::filesystem::exists(targetFolder)) {
//             if (!std::filesystem::create_directory(targetFolder)) {
//                 std::cerr << "Failed to create directory: " << targetFolder << std::endl;
//                 return;
//             }
//         }

//         // Extract the file name from the filePath (extracting everything after the last '/')
//         size_t pos = filePath.find_last_of("/\\");
//         std::string fileName = filePath.substr(pos + 1);

//         // Create the target path for saving the file
//         std::filesystem::path targetPath = targetFolder / fileName;

//         // Debug: Print the full target path
//         std::cout << "Target path: " << targetPath << std::endl;

//         // Open the source file (image) for reading
//         std::ifstream src(filePath, std::ios::binary);
//         if (!src.is_open()) {
//             std::cerr << "Failed to open source file: " << filePath << std::endl;
//             return;
//         }

//         // Open the target file (in the clothing_pics directory) for writing
//         std::ofstream dest(targetPath, std::ios::binary);
//         if (!dest.is_open()) {
//             std::cerr << "Failed to open destination file: " << targetPath << std::endl;
//             return;
//         }

//         // Copy the contents from the source file to the target file
//         dest << src.rdbuf();

//         std::cout << "File has been uploaded to: " << targetPath << std::endl;

//         // Close the file streams
//         src.close();
//         dest.close();
// }



    // void ClosetManager::uploadItem(const std::string& filePath, const std::string& type) {
    //     std::string processedFilePath = processImageWithBackgroundRemover(filePath);

    //     // Create a new ClothingItem with the processed image and the type
    //     ClothingItem* newItem = new ClothingItem(processedFilePath, type);

    //     // Add the item to the appropriate category
    //     if (type == "top") {
    //         tops.push_back(*newItem);
    //     } else if (type == "bottom") {
    //         bottoms.push_back(*newItem);
    //     } else if (type == "shoe") {
    //         shoes.push_back(*newItem);
    //     } else if (type == "coat") {
    //         coats.push_back(*newItem);
    //     }

    //     // Add to uploaded items
    //     uploadedItems.push_back(newItem);

    //     std::cout << "Uploaded and processed " << type << " item: " << processedFilePath << std::endl;
    // }

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

//     // Save a new outfit with just clothing names
//     void saveOutfit(std::string outfitName, std::string topName, std::string bottomName,
//                     std::string shoeName = "", std::string coatName = "") {
//         Outfit newOutfit(outfitName);

//         newOutfit.setTop(topName);
//         newOutfit.setBottom(bottomName);
//         if (!shoeName.empty()) newOutfit.setShoe(shoeName);
//         if (!coatName.empty()) newOutfit.setCoat(coatName);

//         savedOutfits.push_back(newOutfit);
//     }

//     // Add a clothing item to the closet
//     void addClothingItem(std::string type, std::string name) {
//         ClothingItem* item = new ClothingItem(name);

//         if (type == "top") {
//             tops.push_back(item);
//         } else if (type == "bottom") {
//             bottoms.push_back(item);
//         } else if (type == "shoes") {
//             shoes.push_back(item);
//         } else if (type == "coat") {
//             coats.push_back(item);
//         }
//     }

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

