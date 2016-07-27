// #define USE_STDPERIPH_DRIVER
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "stm32f4_discovery.h"

int main(void) {
    STM_EVAL_LEDInit(LED5);
    STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);
 
    volatile int i;
    while (1) {
        // Toggle led if button is pressed
        if(STM_EVAL_PBGetState(BUTTON_USER)){
            STM_EVAL_LEDToggle(LED5);
        }
        // Waste some tome
        for (i = 0; i < 500000; i++);
    }
}