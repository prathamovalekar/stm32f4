#include "stm32f4xx.h"                  // Device header
#include "io.h"

//--------------------------------------------------
//------ Initialising funtion ----------------------
void LED_init(){
// peripheral cloack register(reset and clock control)/ | setting the bit3 enables the "GPIOD" clock (where the leds are connected)
	RCC->AHB1ENR |=(1<<3);//GPIOD
	RCC->AHB1ENR |=(1<<0);//GPIOA
	
//resetting config register 12 to 31 || two bits for each LED || 
	GPIOD->MODER &= ~(0xFF<<12*2);
	
// configure the portD 12,13,14,15 pins as output	
	GPIOD->MODER |= (0x55<<12*2);
}
//--------------------------------------------------


