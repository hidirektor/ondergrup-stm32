/*
 * ErrorProcess.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_ERRORPROCESS_H_
#define INC_ERRORPROCESS_H_

#include <cstdint>
#include <array>
#include <string>

class ErrorProcess {
public:
    static ErrorProcess& getInstance();

    void hata2EEPROM(uint8_t errorCode);
    void hataKoduLcdGoster(uint8_t errorCode);
    void eepromDataFillWithEmpty();

private:
    ErrorProcess() = default;
    ErrorProcess(const ErrorProcess&) = delete;
    ErrorProcess& operator=(const ErrorProcess&) = delete;

    void updateEEPROMData(uint8_t index, uint8_t value);
    void showErrorOnLCD(const std::string& errorMessage);
};

#endif /* INC_ERRORPROCESS_H_ */
