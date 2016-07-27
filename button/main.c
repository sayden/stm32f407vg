#define USE_STDPERIPH_DRIVER
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

int main(void) {
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef GPIO_InitDefLed;
 
    GPIO_InitDefLed.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitDefLed.GPIO_OType = GPIO_OType_PP;
    GPIO_InitDefLed.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitDefLed.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitDefLed.GPIO_Speed = GPIO_Speed_100MHz;

    //Initialize pins
    GPIO_Init(GPIOD, &GPIO_InitDefLed);


    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitDefBtn;
    GPIO_InitDefBtn.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitDefBtn.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitDefBtn.GPIO_PuPd = GPIO_PuPd_DOWN;

    GPIO_Init(GPIOA, &GPIO_InitDefBtn);
 
    volatile int i;
    while (1) {
        // Toggle leds
        if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)){
            GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
        }
        // Waste some tome
        for (i = 0; i < 500000; i++);
    }
}