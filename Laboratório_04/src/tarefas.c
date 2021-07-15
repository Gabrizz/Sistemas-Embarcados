#include "system_tm4c1294.h" // CMSIS-Core
#include "driverleds.h" // device drivers
#include "cmsis_os2.h" // CMSIS-RTOS

osThreadId_t thread1_id, thread2_id, thread3_id, thread4_id;

typedef struct{
  uint8_t led;
  uint32_t tempo;
} LedTempo;

void thread1(void *arg){
  uint8_t state = 0;
  
  while(1){
    state ^= LED1;
    LEDWrite(LED1, state);
    osDelay(100);
  } // while
} // thread1

void thread2(void *arg){
  uint8_t state = 0;
  uint32_t tick;
  LedTempo *aux = (LedTempo *) arg;
  
  while(1){
    tick = osKernelGetTickCount();
    
    state ^= (*aux).led;
    LEDWrite((*aux).led, state);
    
    osDelayUntil(tick + (*aux).tempo);
  } // while
} // thread2

void main(void){
  LEDInit(LED4 | LED3 | LED2 | LED1);
  
  LedTempo var1, var2, var3, var4;
  var1.led = LED1;
  var1.tempo = 100;
  var2.led = LED2;
  var2.tempo = 200;
  var3.led = LED3;
  var3.tempo = 300;
  var4.led = LED4;
  var4.tempo = 400;
  
  osKernelInitialize();
  
  thread1_id = osThreadNew(thread2, &var1, NULL);
  thread2_id = osThreadNew(thread2, &var2, NULL);
  thread3_id = osThreadNew(thread2, &var3, NULL);
  thread4_id = osThreadNew(thread2, &var4, NULL);

  if(osKernelGetState() == osKernelReady)
    osKernelStart();

  while(1);
} // main
