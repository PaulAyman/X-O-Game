#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../common/Types.h"

typedef enum
{
    GPIOA = 0,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF
}GPIOx;

typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7 
}PINx;

typedef enum
{
    INPUT = 0,
    OUTPUT
}IOx;

typedef enum
{
    LOW = 0,
    HIGH
}PINVALUE;

typedef enum
{
   DISABLE =0 ,
   ENABLE
}DigitalEnable;


#define GPIO_PUR_DISABLED 0
#define GPIO_PUR_ENABLED 1

#define GPIO_SENSE_EDGE 0
#define GPIO_SENSE_LEVEL 1

#define GPIO_LL_FE 0
#define GPIO_HL_RE 1

#define GPIO_INTERRUPT_EVENTCONTROLLED 0
#define GPIO_INTERRUPT_BOTHEDGES 1

void GPIO_SetPinDirection(GPIOx portNum, PINx pinNum, IOx pinDirection);
void GPIO_SetPinValue(GPIOx portNum, PINx pinNum, PINVALUE pinValue);
PINVALUE GPIOReadPinValue(GPIOx portNum, PINx pinNum);
void GPIO_SetPinDigEnable(GPIOx portNum, PINx pinNum, DigitalEnable DigitalEnable );
void GPIO_DisableInterrupt(GPIOx portNum, PINx pinNum);

void GPIO_SetPUR(GPIOx portNum, PINx pinNum, u8 u8PURConfig);
void GPIO_SelectInterruptSense(GPIOx portNum, PINx pinNum, u8 u8Sense);
void GPIO_EnableInterrupt(GPIOx portNum, PINx pinNum);
void GPIO_ClearInterrupt(GPIOx portNum, PINx pinNum);
void GPIO_Unlock(GPIOx portNum);
void GPIO_InterruptBothEdges(GPIOx portNum, PINx pinNum , u8 u8BothEdges);
void GPIO_SelectInterruptEvent(GPIOx portNum, PINx pinNum, u8 u8Event);
void PortF_Init(); 
void PortB_Init();
void EnableInterrupts(void);

#endif