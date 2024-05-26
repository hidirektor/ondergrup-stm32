/*
 * LCD.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef I2C_LCD_H
#define I2C_LCD_H

#include "stm32f1xx_hal.h"

class I2CLCD {
public:
    static I2CLCD& getInstance(I2C_HandleTypeDef& hi2c, uint8_t address) {
        static I2CLCD instance(hi2c, address);
        return instance;
    }

    // Disallow copy and assignment
    I2CLCD(const I2CLCD&) = delete;
    void operator=(const I2CLCD&) = delete;

    void init();
    void sendCommand(char cmd);
    void sendData(char data);
    void sendString(const char* str);
    void sendChar(char ch);
    void setCursor(bool state);
    void clear();
    void clearLine(int line);
    void deleteChar(unsigned char row, unsigned char column);
    void setCursorPosition(unsigned char row, unsigned char column);
    void print(unsigned char row, unsigned char column, const char* str);
    void printChar(unsigned char row, unsigned char column, char ch);
    void backlight(char state);

private:
    I2CLCD(I2C_HandleTypeDef& hi2c, uint8_t address);

    void line1();
    void line2();

    I2C_HandleTypeDef& hi2c;
    uint8_t address;
    char backlightState;
};

#endif // I2C_LCD_H
