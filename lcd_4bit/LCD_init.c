#include "stm32f4xx.h"
#include "LCD_init.h"
#include "LCD_drivers.h"
//-----------------------------------------------------------------------------

void LCD_init(){
	RCC->AHB1ENR |=(1U<<3);			// Enabling the Clock on PORTD 
	GPIOD->MODER &= ~(0xFF3F);	// Clearing MODER
															// Data lines:PD4-PD7
															// Control Lines:PD0-PD2
	GPIOD->MODER |=(0x5515);		//Initialising the pins 0,1,2,4,5,6,7 as output pins
	
	LCD4bit_Cmd(0x28);					// MODE SELECT 4bit,2 lines, 5x7 FONT
	LCD4bit_Cmd(0x06);					// Move cursor right
	LCD4bit_Cmd(0x01);					// Clear screen
	LCD4bit_Cmd(0x0F);					// Turn ON the display
	}

//---------------------------------------------------------------------------
	
	
	