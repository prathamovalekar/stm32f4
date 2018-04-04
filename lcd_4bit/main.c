#include "stm32f4xx.h"                  // Device header
#include "delay.h"
#include "LCD_init.h"
#include "LCD_drivers.h"



//---------------------------------------------------------------------------
int main(){

	LCD_init();
	LCD4bit_Cmd(1);
	LCD4bit_Cmd(0x80);
	delay_milli(500);
	LCD_string_write("Hello World!");
	while(1)
	{}	
	}
//-----------------------------------------------------------------------------


