#ifndef __BSP_H__
#define __BSP_H__

#include <stdint.h>

#define RED   (1U << 1)
#define BLUE  (1U << 2)
#define GREEN (1U << 3)


void initValues(void);

uint32_t TickCtr(void);

void delay(uint32_t ticks);

void LedHandleOn(uint32_t color);
void LedHandleOff(uint32_t color);


void SysTick_Handler(void);

#endif // __BSP_H__
