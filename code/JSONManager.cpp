#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include "clothingitem.h"
#include "jsonmanager.h"


#include <QDir>
#include <QDebug>

// Initialize JSON file with a default structure
void JSONManager::initializeClothingItemsJSON(const QString& filePath) {
    // Ensure the directory exists
    QFileInfo fileInfo(filePath);
    QDir dir = fileInfo.dir();
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qDebug() << "Failed to create directory for JSON file:" << dir.path();
            return;
        }
    }

    QFile file(filePath);

    // Check if the file already exists
    if (file.exists()) {
        qDebug() << "JSON file already exists:" << filePath;
        return;
    }

    // Create the default JSON structure
    QJsonObject root;
    root["tops"] = QJsonArray();
    root["bottoms"] = QJsonArray();
    root["shoes"] = QJsonArray();
    root["coats"] = QJsonArray();

    // Write the default structure to the file
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to create JSON file:" << filePath;
        return;
    }

    QJsonDocument doc(root);
    file.write(doc.toJson());
    file.close();

    qDebug() << "Initialized JSON file with default structure:" << filePath;
}

// Load JSON data from a file
QJsonObject JSONManager::load(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        return QJsonObject();
    }
    return QJsonDocument::fromJson(file.readAll()).object();
}

// Save JSON data to a file
void JSONManager::save(const QString& filePath, const QJsonObject& data) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    file.write(QJsonDocument(data).toJson());
}

// Convert a list of ClothingItem pointers to a QJsonArray
QJsonArray JSONManager::toJSONArray(const std::list<ClothingItem*>& items) {
    QJsonArray array;
    for (const auto& item : items) {
        if (item) {
            array.append(item->toJSON());
        }
    }
    return array;
}
