#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

#include "main.h"
#include <stdio.h>
#include <string.h>

#define I2C_LCD_ADDRESS     (0x27<<1)
#define BACKLIGHT 			0x08

#define DISPLAY_ON 			0x0C
#define DISPLAY_OFF			0x08
#define CLEAR_DISPLAY 		0x01
#define RETURN_HOME 		0x02

void lcd_command(uint8_t command);
void lcd_data(uint8_t data);
void i2c_lcd_init(void);
void lcd_string(char *str);
void move_cursor(uint8_t low, uint8_t colum);

#endif