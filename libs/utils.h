#ifndef UTILS_H
#define UTILS_H

#include <nlohmann/json_fwd.hpp>

class QString;

bool readFromFile( const QString& path, nlohmann::json& json );
bool writeToFile ( const QString& path, const nlohmann::json& json, int intend = -1 );
void to_json(nlohmann::json& j, const QString& str);
void from_json(const nlohmann::json& j, QString& str);
#endif // UTILS_H
