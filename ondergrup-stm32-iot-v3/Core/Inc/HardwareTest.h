/*
 * HardwareTest.h
 *
 *  Created on: May 25, 2024
 *      Author: hidirektor
 */

#ifndef INC_HARDWARETEST_H_
#define INC_HARDWARETEST_H_

#include <cstdint>
#include "stm32f1xx_hal.h"

class HardwareTest {
public:
    void i2cTest();

private:
    void initGPIO();
    void setPinHigh(GPIO_TypeDef* port, uint16_t pin);
    void setPinLow(GPIO_TypeDef* port, uint16_t pin);
    void waitForPinHigh(GPIO_TypeDef* port, uint16_t pin);
    void waitForPinLow(GPIO_TypeDef* port, uint16_t pin);
    void deinitGPIO();
    void resetI2C();
};

#endif /* INC_HARDWARETEST_H_ */
