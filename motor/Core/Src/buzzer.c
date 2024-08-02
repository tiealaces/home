/*
 * buzzer.c
 *
 *  Created on: Aug 2, 2024
 *      Author: USER
 */
#include "main.h"

#define Do  383
#define Re  340
#define Mi  304
#define Fa  287
#define Sol 255
#define Ra  227
#define Si  202
#define Doo 191

#define qNote 600
#define wNote 1800

extern int speed;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim10;

uint8_t stop;
uint32_t time = 0;
uint32_t time_cur = 0;

void music()
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

uint16_t song[] =
{
		  Do,Mi,Sol,Do,Mi,Sol,Ra,Ra,Ra,Sol,Fa,Fa,Fa,Mi,Mi,Mi,Re,Re,Re,Do
};

uint16_t time_song[]=
{
		  qNote,qNote,qNote,qNote,qNote,qNote,qNote,qNote,qNote,wNote,
		  qNote,qNote,qNote,qNote,qNote,qNote,qNote,qNote,qNote,wNote
};

	uint16_t i;

	for(i = 0; i < (sizeof(song) / sizeof(song[0])) && stop; i++)
	{

		TIM2 -> PSC = song[i];
		time = HAL_GetTick();
		while( 1){

			time_cur = HAL_GetTick();
			if (time_cur - time > time_song[i]){
				break;
			}
		}
		TIM2 -> CCR1 = 500;
	}
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
}

void music_stop()
{
	TIM2-> CCR1 = 0;
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	stop = 0;

}
