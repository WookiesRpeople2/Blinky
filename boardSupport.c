
#include <stdint.h>  
#include "boardSupport.h"
#include "TM4C123GH6PM.h" 
#include <stdlib.h>

static uint32_t volatile tick;

void SysTick_Handler(void) {
    ++tick;
}

void initValues(void) {
    SYSCTL->RCGCGPIO  |= (1U << 5); // start up GPIO F pins
    SYSCTL->GPIOHBCTL |= (1U << 5); // start up the advaced parfarile bus GPIO F
    GPIOF_AHB->DIR |= (RED | BLUE | GREEN); //give all oif the directions to the dir
    GPIOF_AHB->DEN |= (RED | BLUE | GREEN); // give all the values that will be drained

    SystemCoreClockUpdate();
    SysTick->LOAD = SystemCoreClock / 100U; // Set the reload value
    SysTick->VAL = 0; // Clear the current value
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk;

    __enable_irq();
}

// control the tick function to avoid race conditions
uint32_t TickCtr(void) {
    uint32_t t;

    __disable_irq();
    t = tick;
    __enable_irq();

    return t;
}

void delay(uint32_t ticks) {
    uint32_t ctrl = TickCtr();
    while ((TickCtr() - ctrl) < ticks) {
    }
}

void LedHandleOn(uint32_t color){
	GPIOF_AHB -> DATA |= color;
}


void LedHandleOff(uint32_t color){
	GPIOF_AHB -> DATA &= ~color;
}


