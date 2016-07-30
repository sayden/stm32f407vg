#define USE_STDPERIPH_DRIVER
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

int main(void) {
    /* Initialize USART 2 on pins PA2 (TX) and PA3 (RX) */

    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);

    //Common init type for PA2 and PA3
    GPIO_InitTypeDef paX;
    paX.GPIO_Pin    =   GPIO_Pin_7 | GPIO_Pin_6;
    paX.GPIO_Mode   =   GPIO_Mode_AF;
    paX.GPIO_Speed  =   GPIO_Speed_50MHz;
    paX.GPIO_OType  =   GPIO_OType_PP;
    paX.GPIO_PuPd   =   GPIO_PuPd_UP;
    GPIO_Init(GPIOC, &paX);

    //PA2 and PA3 alternate function configurations
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
    
    USART_InitTypeDef usart;
    usart.USART_BaudRate                =   9600;
    usart.USART_WordLength              =   USART_WordLength_8b;
    usart.USART_StopBits                =   USART_StopBits_1;
    usart.USART_Parity                  =   USART_Parity_No;
    usart.USART_HardwareFlowControl     =   USART_HardwareFlowControl_None;
    usart.USART_Mode                    =   USART_Mode_Tx | USART_Mode_Rx;
    USART_Init(USART6, &usart);

    USART_Cmd(USART6, ENABLE);

    //Init push button
    STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);

    //Init green led
    STM_EVAL_LEDInit(LED3);

    // volatile uint16_t data = 0;
    while (1) {
        if(STM_EVAL_PBGetState(BUTTON_USER)){
            USART_SendData(USART6, 'h');
            STM_EVAL_LEDOn(LED3);
        } else {
            STM_EVAL_LEDOff(LED3);
        }

        // data = USART_ReceiveData(USART6);
        // if (data > 0){
        //     USART_SendData(USART6, 60);
        // }
    }
}