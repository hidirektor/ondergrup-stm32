/*
 * SystemDefaults.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_SYSTEMDEFAULTS_H_
#define INC_SYSTEMDEFAULTS_H_

#include <string>

const std::string MAIN_SERVER = "http://85.95.231.92";
const int MAIN_SERVER_PORT = 3000;
const std::string MAIN_SERVER_WITH_PORT = MAIN_SERVER + ":" + std::to_string(MAIN_SERVER_PORT);

// Flag adresleri
#define UPDATE_FLAG_ADDRESS 0x08003C00  // Güncelleme bayrağı için kullanılacak adres
#define APPLICATION_ADDRESS  0x08004000  // Ana uygulamanın başlayacağı adres
#define NEW_FIRMWARE_ADDRESS 0x08008000  // Yeni firmware'in başlayacağı adres

#endif /* INC_SYSTEMDEFAULTS_H_ */

