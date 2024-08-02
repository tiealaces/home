/*
 * delay.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Stardust
 */

#include "delay.h"

void delay_us(uint16_t us){
	__HAL_TIM_SET_COUNTER(&htim10, 0);

	HAL_TIM_Base_Start(&htim10);
	while(__HAL_TIM_GET_COUNTER(&htim10) < us);

	HAL_TIM_Base_Stop(&htim10);
}

