#define USE_STDPERIPH_DRIVER

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

int main(void) {
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
    GPIO_InitTypeDef GPIO_InitDef;
 
    GPIO_InitDef.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
    //Initialize pins
    GPIO_Init(GPIOG, &GPIO_InitDef);
 
    volatile int i;
    while (1) {
        // Toggle leds
        GPIO_ToggleBits(GPIOG, GPIO_Pin_13 | GPIO_Pin_14);
        // Waste some tome
        for (i = 0; i < 500000; i++);
    }
}