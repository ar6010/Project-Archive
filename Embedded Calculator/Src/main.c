////*
// * 		main.c
// *
// *  	Created on: Dec 18, 2019
// *      Author: Andrew Ramirez
// *
// *      Main program driver
// *      Takes in three values from the keypad to compute a simple calculator operation
// */

//Includes
#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"
#include "uart_driver.h"
#include "delay.h"
#include "keypad.h"

//Defines
#define F_CPU 16000000UL
#define ARSIZE 10

// main
int main(){

	//Initialization of usart, lcd, and ints
	init_usart2(19200,F_CPU);
	lcd_init();
	keypad_init();
	int a,op,b,calc;
	char num[2];
	int aInt, bInt;
	char keys[17] = {'0', '1', '2', '3', 'a',
					 	 '4', '5', '6', 'b',
						 '7', '8', '9', 'c',
						 '*', '0', '#', 'd'};
//	char buffer[5] = {0};

	while(1){
	// Read in characters for function
		writeString("First Int", 9);
		a = keys[keypad_getKey()];
		clear();
		writeString("Operator", 8);
		op = keys[keypad_getKey()];
		clear();
		writeString("Second Int", 10);
		b = keys[keypad_getKey()];
		clear();

//		Calculate the result, depending on the operation

        //Addition
		if(op == 'a'){
			aInt = a - 48;
			bInt = b - 48;
			calc = aInt + bInt;
			writeData(a);
			writeData('+');
			writeData(b);
			writeData('=');
			sprintf(num, "%d", calc);
			writeString(num, 2);

        //Subtraction
		} else if(op == 'b'){
			aInt = a - 48;
			bInt = b - 48;
			calc = aInt - bInt;
			writeData(a);
			writeData('-');
			writeData(b);
			writeData('=');
			sprintf(num, "%d", calc);
			writeString(num, 2);

        //Multiplication
		} else if(op == 'c'){
			aInt = a - 48;
			bInt = b - 48;
			calc = aInt * bInt;
			writeData(a);
			writeData('*');
			writeData(b);
			writeData('=');
			sprintf(num, "%d", calc);
			writeString(num, 2);

        //Division
		} else if(op == 'd'){
			if(b == '0'){
				writeString("Can't Div by 0", 14);

			} else {
				aInt = a - 48;
				bInt = b - 48;
				calc = aInt / bInt;
				writeData(a);
				writeData('/');
				writeData(b);
				writeData('=');
				sprintf(num, "%d", calc);
				writeString(num, 2);
			}
		} else {
			writeString("No Valid OP", 11);
		}

		delay_1ms(5000);
		clear();



//	Clear \n from input stream
//	throwaway= getchar();

	}

	return 0;
}

//			sprintf(buffer[0], "%d", a);
//			sprintf(buffer[1], "%d", '+');
//			sprintf(buffer[2], "%d", b);
//			sprintf(buffer[3], "%d", '=');
//			sprintf(buffer[4], "%d", calc);//Print equation to buffer
//			for(int i = 0; i < 4; i++){
//				writeData(buffer[i]);		//Write each item in the buffer to the lcd
//			}
