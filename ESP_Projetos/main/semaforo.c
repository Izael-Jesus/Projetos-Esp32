#include <stdio.h>
#include"driver/gpio.h"

#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

#define RED GPIO_NUM_2 //Vermelho 
#define YLW GPIO_NUM_33  //Amarelo
#define GRN GPIO_NUM_32  //Verde  

void app_main(void)
{
    // Configurar as GPIO como SAIDAS
    gpio_set_direction(RED, GPIO_MODE_OUTPUT);
    gpio_set_direction(YLW, GPIO_MODE_OUTPUT);
    gpio_set_direction(GRN, GPIO_MODE_OUTPUT);

    while(1){

        // Iniciar Semaforo

        gpio_set_level(RED, 1);  // Vermelho ON
        gpio_set_level(YLW, 0);  // Amarelo OFF
        gpio_set_level(GRN, 0);  // Verde OFF

        vTaskDelay(pdMS_TO_TICKS(5000)); // Delay 5 segundos

        gpio_set_level(RED, 0);  // Vermelho OFF
        gpio_set_level(YLW, 1);  // Amarelo ON
        gpio_set_level(GRN, 0);  // Verde OFF


        vTaskDelay(pdMS_TO_TICKS(3000)); // Delay 3 segundos 

        gpio_set_level(RED, 0);  // Vermelho OFF
        gpio_set_level(YLW, 0);  // Amarelo OFF
        gpio_set_level(GRN, 1);  // Verde ON

        vTaskDelay(pdMS_TO_TICKS(5000)); // Delay 5 segundos 
    }


}
