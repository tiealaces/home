/*
 * delay.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Stardust
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include "stm32f4xx_hal.h"
#include "tim.h"

// timer/counter 10번은 16-bit
void delay_us(uint16_t us);

#endif /* INC_DELAY_H_ */
