/*
 * delay.h
 *
 *
 */

//include guards
#ifndef DELAY_H_
#define DELAY_H_

//Add address for these memory mapped registers
//Check STM Programming Manual Chapter 4.5
#define STK_CTRL (volatile uint32_t*) 0xE000E010
#define STK_LOAD (volatile uint32_t*) 0xE000E014
#define STK_VAL (volatile uint32_t*) 0xE000E018

#define EN 1
#define TICKINT 0b10
#define CLKSOURCE 0b100
#define COUNTFLAG ((*STK_CTRL&(0b10000000000000000))>>16)

/*
 * delay_1ms
 * 		Busy wait for n ms
 *
 * 		For n iterations
 * 			load number of cycles for 1 ms
 * 			set one to enable and clock source
 *
 * 			wait for countflag to be set
 */
extern void delay_1ms(uint32_t n);

extern void delay(uint32_t n);

#endif /* DELAY_H_ */
