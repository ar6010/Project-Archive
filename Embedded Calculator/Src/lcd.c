/*
 * 		lcd.c
 *
 *  	Created on: Dec 18, 2019
 *      Author: Andrew Ramirez
 *
 *      lcd driver code
 */

#include "lcd.h"
#include "delay.h"
#include <inttypes.h>
#include <stdio.h>

void lcd_init(){

	//port_setup();

	//Enable both GPIOs
	*RCC_AHB1ENR |= (0x5);

	//Set the MODER for GPIOA and GPIOC

	//Set bits
	*GPIOC_BASE &= ~(0b111111<<16);
	*GPIOC_BASE |= (0b010101<<16);

	*GPIOA_BASE &= ~(0b1111111111111111<<8);
	*GPIOA_BASE |= (0b0101010101010101<<8);

	//Initialize Display
	//writeInstruction(0x30);
	//delay_1ms(50);
	//writeInstruction(0x30);
	//delay_1ms(50);
	//writeInstruction(0x30);
	delay_1ms(3);

	writeInstruction(0x38);
	writeInstruction(0x38);
	writeInstruction(0x0F);//
	writeInstruction(0x01);//10
	//writeInstruction(0x0C);
	writeInstruction(0x06);

	//writeInstruction(0x01);

}

void writeInstruction(uint8_t instr){
	//Set RS=0,RW=0,E=0
	*GPIOC_ODR &= ~(0x7<<8);
	//Set Enable
	*GPIOC_ODR |= E;
	//delay_1ms(1);//Greater than 460ns
	//instr -> data bus
	*GPIOA_ODR &= ~(0xFF<<4);
	*GPIOA_ODR |= (instr<<4);
	//delay_1ms(1);//Greater than 80ns
	//Turn off Enable
	*GPIOC_ODR &= ~(1<<10);
	delay_1ms(2);

}

void writeData(uint8_t instr){
	//Set RS=1,RW=0,E=0
	*GPIOC_ODR &= ~(0x7<<8);
	*GPIOC_ODR |= (RS);
	//Set Enable
	*GPIOC_ODR |= E;
	//delay_1ms(1);//Greater than 460ns
	//instr -> data bus
	*GPIOA_ODR &= ~(0xFF<<4);
	*GPIOA_ODR |= (instr<<4);
	//delay_1ms(1);//Greater than 80ns
	//Turn off Enable
	*GPIOC_ODR &= ~(1<<10);
	delay_1ms(2);

}

void writeString(char string[], int size){

	for(int i = 0; i < size; i++){
		writeData(string[i]);
	}

}

void clear(){
	writeInstruction(0x1);
}
