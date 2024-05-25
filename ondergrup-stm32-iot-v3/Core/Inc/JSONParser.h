/*
 * JSONParser.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include <map>

class JSONParser {
public:
    JSONParser();
    ~JSONParser();

    bool parse(const std::string& jsonString);
    std::string getString(const std::string& key);
    int getInt(const std::string& key);
    bool getBool(const std::string& key);

private:
    std::map<std::string, std::string> data;

    void trim(std::string& str);
    void parseKeyValue(const std::string& keyValue);
};

#endif // JSONPARSER_H

