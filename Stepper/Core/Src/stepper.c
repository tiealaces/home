/*
 * stepper.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Stardust
 */

#include "stepper.h"

void stepMotor(uint8_t step){
	HAL_GPIO_WritePin(IN1_Port, IN1_Pin, HALF_STEP_SEQ[step][0]);
	HAL_GPIO_WritePin(IN2_Port, IN2_Pin, HALF_STEP_SEQ[step][1]);
	HAL_GPIO_WritePin(IN3_Port, IN3_Pin, HALF_STEP_SEQ[step][2]);
	HAL_GPIO_WritePin(IN4_Port, IN4_Pin, HALF_STEP_SEQ[step][3]);
}
void rotateSteps(uint16_t steps, uint8_t direction){
	for(uint16_t i=0; i<steps; i++){
		uint8_t step;
		// 회전 방향에 맞춰서 스텝 패턴 설정
		if(direction == DIR_CW){
			step = i % 8;
		}
		else{
			step = 7 - (i % 8);
		}
		stepMotor(step);
		delay_us(1000);	// 각 스텝간의 지연
	}
}
void rotateDegrees(uint16_t degrees, uint8_t direction){
	uint16_t steps = (uint16_t)(((uint32_t)degrees * STEPS_PER_REVOLATION) / 360);
	rotateSteps(steps, direction);
}
