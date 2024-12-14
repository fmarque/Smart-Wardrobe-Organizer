#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include "clothingitem.h"

class JSONManager {
public:
    QJsonObject load(const QString& filePath) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly)) {
            return QJsonObject();
        }
        return QJsonDocument::fromJson(file.readAll()).object();
    }

    void save(const QString& filePath, const QJsonObject& data) {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly)) {
            return;
        }
        file.write(QJsonDocument(data).toJson());
    }

    QJsonArray toJSONArray(const QList<ClothingItem>& items) {
        QJsonArray array;
        for (const auto& item : items) {
            array.append(item.toJSON());
        }
        return array;
    }
};
