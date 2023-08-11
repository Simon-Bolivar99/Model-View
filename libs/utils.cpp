#include <libs/utils.h>
#include <nlohmann/json.hpp>

#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include <QStandardPaths>



bool writeToFile(const QString &path, const nlohmann::json &json, int intend )
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }
    file.write(json.dump(intend).c_str());
    file.close();

    return true;
}


bool readFromFile(const QString &path, nlohmann::json& json)
{
    if (!QFile::exists(path)) {
        return false;
    }

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    json = nlohmann::json::parse(file.readAll().toStdString(), nullptr, false);
    if (json.is_discarded()) {
        qDebug() << "readFromFile:: json discarted";
        return false;
    }

    return true;

}

void from_json(const nlohmann::json &j, QString &str)
{
    str = j.get<std::string>().c_str();
}

void to_json(nlohmann::json& j, const QString& str) {
    j = str.toStdString();
}

