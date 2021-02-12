/*
 * led.c
 *
 *  Created on: Dec 1, 2018
 *      Author: livingston
 *      Modified by: Andrew Ramirez
 *      Date: 12/11/19
 */

#include "led.h"
#include "delay.h"
#include <inttypes.h>
#include <stdio.h>

//Speed value for the user
uint8_t speedVal = 4;
//Speed value for the program (speedVal*20)
uint8_t RspeedVal = 80;

void led_init(){

	// '*' dereferences pointer, allows access to memory

	//Configure the RCC
	*RCC_AHB1ENR |= (1<<GPIOBEN);

	//Set the MODER
	*GPIOB_MODER &= ~(0x3FFF<<10);
	*GPIOB_MODER |= (0x555<<10);

	*GPIOB_MODER &= ~(0xFF<<24);
	*GPIOB_MODER |= (0x55<<24);

}

void led_allOn(){
	//Set ODR to all on
	*GPIOB_ODR |= (0b11110111111<<5);
}

void led_allOff(){
	//Set ODR to all off
	*GPIOB_ODR &= ~(0b11110111111<<5);
}

void led_on(uint8_t ledIndex){
	//Offset the given index to fit the pin values
	int offset = ledIndex+5;
	//Set the ODR to the index+offset
	*GPIOB_ODR |= (0b1<<offset);

}

void led_off(uint8_t ledIndex){
	//Offset the given index to fit the pin values
	int offset = ledIndex+5;
	//Set the ODR to the index+offset
	*GPIOB_ODR &= ~(0b1<<offset);
}

void led_scan(){
	//Turn the first light on, then back off, and repeat for each following led
	//Delay controlled by speed
	for(int i = 0; i < 10; i++){
		if(i != 6){
		led_on(i);
		delay_1ms(RspeedVal);
		led_off(i);
		delay_1ms(RspeedVal);
		}
	}
	led_allOff();
	//Reverse the process above
	for(int i = 10; i >= 0; i--){
		if(i != 6){
			led_on(i);
			delay_1ms(RspeedVal);
			led_off(i);
			delay_1ms(RspeedVal);
		}
	}
}

void led_flash(){
	//Turn the lights on, then off, with a delay in between set by the program speed value
	for(int i = 0; i < 9; i++){
	led_allOn();
	delay_1ms(RspeedVal);
	led_allOff();
	delay_1ms(RspeedVal);
	}
}

void led_setSpeed(uint8_t speed){
	//Multiply the speed value by 20 to get the program speed value
	RspeedVal = speed*20;
}

void led_incSpeed(){
	//If the speed value is greater than 0, subtract 1
	if(speedVal > 0){
		speedVal--;
	}
	led_setSpeed(speedVal);
}

void led_decSpeed(){
	//If the speed value is less than 9, add 1
	if(speedVal < 9){
			speedVal++;
		}
	led_setSpeed(speedVal);
}

uint8_t led_speedVal(){
	//Return the speed value
	return speedVal;
}
