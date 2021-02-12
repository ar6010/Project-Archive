/*
 * delay.c
 *
 *  	Created on: Jan 22, 2020
 *      Author: Andrew Ramirez
 *      Date: Jan 29, 2020
 */

#include <inttypes.h>
#include "delay.h"  //include declaration header file

void delay_1ms(uint32_t n){

	int temp = n;

	//Move the reload value to the SysTick
	*STK_LOAD = 16000;

	while(temp > 0){
		//Enable Clock
		*STK_CTRL |= CLKSOURCE;
		*STK_CTRL |= EN;
		//Wait until count flag fires
	while(COUNTFLAG != 1);
	//Reset clock and decrement count variable
		*STK_CTRL &= 0xFFFFFFFE;
		temp--;
	}
}

//void delay(uint32_t n){
//
//	//Move the reload value to the SysTick
//	//16,000,000 cycles per second
//	*STK_LOAD = 16000000/n;
//
//	while(temp > 0){
//		//Enable Clock
//		*STK_CTRL |= CLKSOURCE;
//		*STK_CTRL |= EN;
//		//Wait until count flag fires
//	while(COUNTFLAG != 1);
//	//Reset clock and decrement count variable
//		*STK_CTRL &= 0xFFFFFFFE;
//		temp--;
//	}
//}
