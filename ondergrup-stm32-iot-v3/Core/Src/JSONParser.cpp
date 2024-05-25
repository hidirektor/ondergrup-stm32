/*
 * JSONParser.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "JSONParser.h"
#include <algorithm>
#include <sstream>

JSONParser::JSONParser() {}

JSONParser::~JSONParser() {}

bool JSONParser::parse(const std::string& jsonString) {
    std::string trimmedJson = jsonString;
    trim(trimmedJson);

    if (trimmedJson.front() == '{' && trimmedJson.back() == '}') {
        trimmedJson = trimmedJson.substr(1, trimmedJson.size() - 2);
    } else {
        return false;
    }

    std::istringstream ss(trimmedJson);
    std::string keyValue;
    while (std::getline(ss, keyValue, ',')) {
        parseKeyValue(keyValue);
    }

    return true;
}

std::string JSONParser::getString(const std::string& key) {
    return data[key];
}

int JSONParser::getInt(const std::string& key) {
    return std::stoi(data[key]);
}

bool JSONParser::getBool(const std::string& key) {
    return data[key] == "true";
}

void JSONParser::trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

void JSONParser::parseKeyValue(const std::string& keyValue) {
    size_t colonPos = keyValue.find(':');
    if (colonPos != std::string::npos) {
        std::string key = keyValue.substr(0, colonPos);
        std::string value = keyValue.substr(colonPos + 1);
        trim(key);
        trim(value);

        if (key.front() == '\"' && key.back() == '\"') {
            key = key.substr(1, key.size() - 2);
        }
        if (value.front() == '\"' && value.back() == '\"') {
            value = value.substr(1, value.size() - 2);
        }

        data[key] = value;
    }
}


