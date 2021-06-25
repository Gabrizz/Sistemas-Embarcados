#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

uint8_t LED_D1 = 0;

void main(void){
  
  SysCtlClockFreqSet(SYSCTL_OSC_INT | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_320, 24000000); // 24MHz
  //SysCtlClockFreqSet(SYSCTL_OSC_INT | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_320, 120000000); // 120MHz
  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D3 = PF4, LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
  
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0); // LED D4 como saída
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0); // LED D4 apagado
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);
  
  // Para 24MHz:
  // 1/(24*10^6) = 4.1666*10^(-8) ns
  // 4.1666*10^(-8) * 3 instruções/loop = 125 ns
  // 1/(125*10^(-9)) = 8*10^6 ciclos para obter intervalos de 1 segundo
  
  // Para 120MHz:
  // 1/(120*10^6) = 8.333*10^(-9) ns
  // 8.333*10^(-9) * 3 instruções/loop = 25 ns
  // 1/(25*10^(-9)) = 40*10^6 ciclos para obter intervalos de 1 segundo
  
  // Com o auxílio de um cronômetro, foi analisado o tempo total utilizado
  // para cada modelo realizar 10 ciclos. Na frequência de 24MHz levou
  // 10 segundos e na de 120MHz levou 14 segundos, nos dando uma diferença
  // de 4 segundos entre elas.
  // 24MHz completou 1 ciclo/segundo.
  // 120MHz completou 0.714 ciclo/segundo.
  
  while(1){
    SysCtlDelay(8000000);
    LED_D1 ^= GPIO_PIN_1; // Troca estado do LED D1
    GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, LED_D1); // Acende ou apaga LED D1
      
  } // while
  
} // main