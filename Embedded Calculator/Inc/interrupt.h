#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <stdio.h>
#include <stdlib.h>

#define RCC_AHB1ENR (volatile uint32_t*) 0x40023830 //Check
#define RCC_APB2ENR (volatile uint32_t*) 0x40023844

#define GPIOB (volatile uint32_t*) 0x040020400

#define GPIOA (volatile uint32_t*) 0x040020000
#define GPIOA_IDR (volatile uint32_t*) 0x040020010
#define GPIOA_PUPDR (volatile uint32_t*) 0x04002000C

#define SYSCFG_EXTICR1 (volatile uint32_t*) 0x040013008
#define SYSCFG_EXTICR4 (volatile uint32_t*) 0x040013014

#define EXTI_IMR (volatile uint32_t*) 0x040013C00
#define EXTI_PR (volatile uint32_t*) 0x040013C14
#define EXTI_FTSR (volatile uint32_t*) 0x040013C0C

#define NVIC_ISER0 (volatile uint32_t*) 0xE000E100
#define NVIC_ISER1 (volatile uint32_t*) 0xE000E104

//Define interrupt, check startup call for name
extern void init_int(int a, int b, int c);

extern void EXTI0_IRQHandler (void) __attribute__ ((isr));

extern void EXTI1_IRQHandler (void) __attribute__ ((isr));

extern void EXTI15_10_IRQHandler (void) __attribute__ ((isr));

extern int checkNum();

#endif

