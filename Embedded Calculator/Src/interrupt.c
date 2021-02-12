/*
 * interrupt.c
 *
 *  	Created on: Jan 29, 2020
 *      Author: Andrew Ramirez
 *      Date: Feb 5, 2020
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interrupt.h"
#include "led.h"

int a = 0;
int b = 0;
int count = 0;
int rcount = 0;
int lcount = 0;

int num1 = 0;
int num2 = 0;
int num3 = 0;

int status = 0;

void init_int(int a, int b, int c){

	//Enable clock for syscfg
	*(RCC_APB2ENR) |= 1<<14;
	//Enable clock for gpio a
	*(RCC_AHB1ENR) |= 0b01;
	//Setup PA0-1 and PA12 as input
	*(GPIOA) &= ~(0xF);
	*(GPIOA) &= ~(0x3<<24);
	*GPIOA_PUPDR &= ~(0xF);
	*GPIOA_PUPDR |= (0x5);
	*GPIOA_PUPDR &= ~(0x3<<24);
	*GPIOA_PUPDR |= (0x1<<24);
	//Connect PA to EXTI
	*SYSCFG_EXTICR1 &= ~(0xFF);
	*SYSCFG_EXTICR4 &= ~(0xF<<4);
	//Unmask EXTI0-1 and 12 in EXTI
	*EXTI_IMR |= 0b11;
	*EXTI_IMR |= 1<<12;
	//Set to falling edge
	*EXTI_FTSR |= 0b11;
	*EXTI_FTSR |= 1<<12;
	//Enable interrupt in NVIC
	*(NVIC_ISER0) |= 0xC0;
	*(NVIC_ISER1) |= 1<<8;

	//Set combination
	num1 = a;
	num2 = b;
	num3 = c;

}


void EXTI0_IRQHandler (void) {
	if((*(EXTI_PR)&(1)) != 0){
		//Clear
		*EXTI_PR |= (0b1);
		//*EXTI_PR |= (1<<1);
		//Check direction
		a = (*GPIOA_IDR && 0xFFFE);
		b = (*GPIOA_IDR && 0xFFFD) >> 1;
		//Increment direction
//		if((a == b)){
//			count--;
//			led_on(8);
//			delay_1ms(50);
//			led_off(8);
//		} else
		if (a != b){
			rcount++;
			led_on(8);
			delay_1ms(50);
			led_off(8);
		}
		//Check if position = 0
		if(rcount == -12 || rcount == 12){
			rcount = 0;
		}
	}

}

void EXTI1_IRQHandler (void) {
	if((*(EXTI_PR)&(1<<1)) != 0){
			//Clear
			*EXTI_PR |= (1<<1);
			//*EXTI_PR |= (0b1);
			//Check direction
			a = (*GPIOA_IDR && 0xFFFE);
			b = (*GPIOA_IDR && 0xFFFD) >> 1;
			//Increment direction
//			if((a == b)){
//				count--;
//				led_on(8);
//				delay_1ms(50);
//				led_off(8);
//			} else
			if (a != b){
				lcount--;
				led_on(1);
				delay_1ms(50);
				led_off(1);
			}
			//Check if position = 0
			if(lcount == -12 || lcount == 12){
				lcount = 0;
			}
		}
}

void EXTI15_10_IRQHandler (void) {
	if((*(EXTI_PR)&(1<<12)) != 0){
		//Clear
		*EXTI_PR |= (1<<12);
		led_allOn();
		delay_1ms(50);
		led_allOff();
		count = rcount - lcount;
		printf("%d", count);
		//checkNum();

	}
}


int checkNum(){
	int retVal = 0;
	//Check 1st digit
	if(status == 0){
		if(count == num1 || 1 + count == num1){
			led_allOn();
			delay_1ms(50);
			led_allOff();
			status++;
		}
	//Check 2nd digit
	} else if (status == 1){
		if(count == num2 || 1 + count == num2){
			led_allOn();
			delay_1ms(50);
			led_allOff();
			status++;
		}
	//Check 3rd digit
	} else if (status == 2){
		if(count == num3 || 1 + count == num3){
			led_allOn();
			delay_1ms(50);
			led_allOff();
			status = 0;
			retVal = 1;
		}
	}
	return retVal;
}
