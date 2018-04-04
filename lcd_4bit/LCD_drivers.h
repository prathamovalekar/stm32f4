#ifndef __LCD_DRIVERS_H__
#define __LCD_DRIVERS_H__


void LCD4bit_Cmd(unsigned char command);
void LCD4bit_Data(unsigned char data);
void LCD_write4bit(unsigned char data,unsigned char control);
void LCD_string_write(char* st_string);

#define RS 1 //0x01 PORTD 0
#define RW 2 //0x02 PORTD 0
#define EN 4 //0x04 PORTD 0


#endif

