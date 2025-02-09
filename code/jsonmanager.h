#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <list>
#include "clothingitem.h"

class JSONManager {
public:
    // Load JSON data from a file and return it as a QJsonObject
    void initializeClothingItemsJSON(const QString& filePath);
    void initializeOutfitsJSON(const QString& filePath);
    QJsonObject load(const QString& filePath);

    // Save JSON data to a file
    void save(const QString& filePath, const QJsonObject& data);

    // Convert a list of ClothingItem pointers to a QJsonArray
    QJsonArray toJSONArray(const std::list<ClothingItem*>& items);

};

#endif // JSONMANAGER_H
