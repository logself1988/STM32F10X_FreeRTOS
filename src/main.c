#include "stm32f10x.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

#define LED_ON()     GPIO_SetBits(GPIOB,GPIO_Pin_0)
#define LED_OFF()    GPIO_ResetBits(GPIOB,GPIO_Pin_0)

static void LedInitial(void);
static void vLedTask(void *pvParameters);

int main(void)
{
  LedInitial();
  xTaskCreate(vLedTask,(const char * const)"LED controller",configMINIMAL_STACK_SIZE,NULL,tskIDLE_PRIORITY+3,NULL);
  vTaskStartScheduler();
  
  return 0;
}

void vLedTask(void *pvParameters)
{
  for(;;)
    {
      LED_ON();
      vTaskDelay(100/portTICK_RATE_MS);
      LED_OFF();
      vTaskDelay(100/portTICK_RATE_MS);
    }
}

void LedInitial(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOB,&GPIO_InitStructure);
}

