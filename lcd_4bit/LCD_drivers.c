#include "stm32f4xx.h"
#include "LCD_drivers.h"
#include "delay.h"

//------------------------------------------------------------------------------
// To send command to the LCD in 4 bit mode
void LCD4bit_Cmd(unsigned char command){
	LCD_write4bit(command & 0xF0,0);
	LCD_write4bit(command<<4,0);
	
	if (command<4)
		delay_milli(2);
	else
		delay_micro(40);
				
	}
//------------------------------------------------------------------------------
// To send command to the LCD in 4 bit mode
void LCD4bit_Data(unsigned char data){
	LCD_write4bit(data & 0xF0, RS);
	LCD_write4bit(data << 4,RS);
	delay_micro(40);
	
	}
	
//----------------------------------------------------------------------------
// sending the command/ data using only 4 lines	
void LCD_write4bit(unsigned char data,unsigned char control){
	data &= 0xF0;			//upper 4bits saved of data/command
	control &= 0x0F;	// lower 4bits saved of control signal
	
	GPIOD->ODR = data | control;
	GPIOD->ODR = data | control | EN;
	delay_micro(0);
	GPIOD->ODR = data;
	}

//---------------------------------------------------------------------------	
// Function to pass string to the LCD	
	
	void LCD_string_write(char* st_string){
		while(*st_string > 0){
			LCD4bit_Data(*st_string++);
		}
	}	
//--------------------------------------------------------------------------

	
