/*
 * 		lcd.h
 *
 *  	Created on: Dec 18, 2019
 *      Author: Andrew Ramirez
 *
 *      lcd header file
 */
//Include Guards (More to come)
#ifndef LCD_H_
#define LCD_H_

#include <inttypes.h>


//Find the Addresses for the following memory mapped control registers
//Check the STM Reference Manual
//Memory Map - Chapter 2.2
//RCC 	- Chapter 6.3.28
//GPIO	- Chapter 7.4
#define RCC_AHB1ENR (volatile uint32_t*) 0x40023830

#define GPIOA_BASE (volatile uint32_t*) 0x40020000
#define GPIOC_BASE (volatile uint32_t*) 0x40020800

#define GPIOA_ODR (volatile uint32_t*) 0x40020014
#define GPIOC_ODR (volatile uint32_t*) 0x40020814
//Addresses for the following memory mapped control registers
#define GPIO_BSRR 0x18

//Set bits
#define RS 1<<8
#define RW 1<<9
#define E 1<<10

//Set BSRR Functions
//#define RS_SET 1<<RS
//#define RS_CLR 1<<(RS+16)
//#define RW_SET 1<<RW
//#define RW_CLR 1<<(RW+16)
//#define E_SET 1<<E
//#define E_CLR 1<<(E+16)

//Initialize Display
extern void lcd_init();

//Write Display Instructions
void writeInstruction(uint8_t instr);

//Write Data to Display
extern void writeData(uint8_t instr);

//Write a string to the LCD
extern void writeString(char string[], int size);

//Clear display
extern void clear();


#endif
