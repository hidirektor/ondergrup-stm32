/*
 * LCD.cpp
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */


#include "LCD.h"

#define _CLEAR      0x01
#define _FIRST_ROW  0x80
#define _SECOND_ROW 0xC0

I2CLCD::I2CLCD(I2C_HandleTypeDef& hi2c, uint8_t address)
    : hi2c(hi2c), address(address), backlightState(0x00) {}

void I2CLCD::init() {
    sendCommand(0x02);
    sendCommand(0x28);
    sendCommand(0x0c);
    sendCommand(0x80);
    backlight(1);
}

void I2CLCD::sendCommand(char cmd) {
    char data_u = (cmd & 0xf0);
    char data_l = ((cmd << 4) & 0xf0);
    uint8_t data_t[4] = {
        data_u | 0x0C,
        data_u | 0x08,
        data_l | 0x0C,
        data_l | 0x08
    };

    while (HAL_I2C_GetError(&hi2c) == HAL_I2C_ERROR_AF);
    while (HAL_I2C_GetState(&hi2c) != HAL_I2C_STATE_READY);

    if (backlightState == 0) {
        for (uint8_t i = 0; i <= 3; i++) {
            data_t[i] &= ~(1UL << 3);
        }
    } else {
        for (uint8_t i = 0; i <= 3; i++) {
            data_t[i] |= 1UL << 3;
        }
    }

    HAL_I2C_Master_Transmit(&hi2c, address, data_t, 4, 100);
}

void I2CLCD::sendData(char data) {
    char data_u = (data & 0xf0);
    char data_l = ((data << 4) & 0xf0);
    uint8_t data_t[4] = {
        data_u | 0x0D,
        data_u | 0x09,
        data_l | 0x0D,
        data_l | 0x09
    };

    while (HAL_I2C_GetError(&hi2c) == HAL_I2C_ERROR_AF);
    while (HAL_I2C_GetState(&hi2c) != HAL_I2C_STATE_READY);

    if (backlightState == 0) {
        for (uint8_t i = 0; i <= 3; i++) {
            data_t[i] &= ~(1UL << 3);
        }
    } else {
        for (uint8_t i = 0; i <= 3; i++) {
            data_t[i] |= 1UL << 3;
        }
    }

    HAL_I2C_Master_Transmit(&hi2c, address, data_t, 4, 100);
}

void I2CLCD::sendString(const char* str) {
    while (*str) {
        sendData(*str++);
    }
}

void I2CLCD::sendChar(char ch) {
    char data_u = (ch & 0xf0);
    char data_l = ((ch << 4) & 0xf0);
    uint8_t data_t[4] = {
        data_u | 0x0D,
        data_u | 0x09,
        data_l | 0x0D,
        data_l | 0x09
    };

    while (HAL_I2C_GetError(&hi2c) == HAL_I2C_ERROR_AF);
    while (HAL_I2C_GetState(&hi2c) != HAL_I2C_STATE_READY);

    if (backlightState == 0) {
        for (uint8_t i = 0; i <= 3; i++) {
            data_t[i] &= ~(1UL << 3);
        }
    } else {
        for (uint8_t i = 0; i <= 3; i++) {
            data_t[i] |= 1UL << 3;
        }
    }

    HAL_I2C_Master_Transmit(&hi2c, address, data_t, 4, 100);
}

void I2CLCD::setCursor(bool state) {
    if (state) {
        sendCommand(0x0E);
        sendCommand(0x0F);
    } else {
        sendCommand(0x0C);
    }
}

void I2CLCD::clear() {
    sendCommand(_CLEAR);
    HAL_Delay(2);
}

void I2CLCD::clearLine(int line) {
    if (line == 1) {
        line1();
    } else {
        line2();
    }
    sendCommand(0x01);
}

void I2CLCD::deleteChar(unsigned char row, unsigned char column) {
    setCursorPosition(row, column);
    sendChar(' ');
}

void I2CLCD::setCursorPosition(unsigned char row, unsigned char column) {
    if (row == 1) {
        sendCommand(0x80 + (column - 1));
    } else if (row == 2) {
        sendCommand(0xC0 + (column - 1));
    }
}

void I2CLCD::print(unsigned char row, unsigned char column, const char* str) {
    setCursorPosition(row, column);
    sendString(str);
}

void I2CLCD::printChar(unsigned char row, unsigned char column, char ch) {
    setCursorPosition(row, column);
    sendChar(ch);
}

void I2CLCD::backlight(char state) {
    backlightState = state;
    sendCommand(0x00);
}

void I2CLCD::line1() {
    sendCommand(0x80);
}

void I2CLCD::line2() {
    sendCommand(0xC0);
}
