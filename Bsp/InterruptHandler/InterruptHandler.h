#ifndef __INTERRUPTHANDLER_H
#define __INTERRUPTHANDLER_H

//BSP
#define STM32F4XX
#define USART
#define TIMER
#define CAN

#ifdef STM32F1XX
#include "stm32f1xx_hal.h"
#endif // DEBUG

#ifdef STM32F4XX
#include "stm32f4xx_hal.h"
#endif // DEBUG

#ifdef TIMER
#include "tim.h"
#define TimerBase_Handler      htim2
#endif // TIMER

#ifdef USART
#include "usart.h"
#define Usart_Handler1         huart6
#define Usart_BufSize1         10
#endif // DEBUG

#ifdef CAN
#include "can.h"
#define CAN_Handler1           hcan1
#endif // DEBUG

//APP
#include "CAN_3508.h"

void InterruptInit(void);

#endif // !__INTERRUPTHANDLER_H
