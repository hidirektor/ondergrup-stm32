/*
 * dwt_stm32_delay.h
 *
 *  Created on: Aug 10, 2024
 *      Author: hidirektor
 */

#ifndef INC_DWT_STM32_DELAY_H_
#define INC_DWT_STM32_DELAY_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f1xx_hal.h"

/**
 * @brief  Initializes DWT_Cycle_Count for DWT_Delay_us function
 * @return Error DWT counter
 *         1: DWT counter Error
 *         0: DWT counter works
 */
uint32_t DWT_Delay_Init(void);
void DWT_Delay_us(volatile uint32_t microseconds);


/**
 * @brief  This function provides a delay (in microseconds)
 * @param  microseconds: delay in microseconds
 */


#ifdef __cplusplus
}
#endif

#endif /* INC_DWT_STM32_DELAY_H_ */
