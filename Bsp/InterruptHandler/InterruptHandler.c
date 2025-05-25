#include "InterruptHandler.h"

uint8_t Usart_Handler1_Buf[Usart_BufSize1] = {0};

void InterruptInit(void)
{
    #ifdef TIMER
    __HAL_TIM_CLEAR_FLAG (&TimerBase_Handler, TIM_FLAG_UPDATE);
    HAL_TIM_Base_Start_IT(&TimerBase_Handler);
    #endif // TIMER

    #ifdef USART
    HAL_UART_Receive_IT(&Usart_Handler1, Usart_Handler1_Buf, Usart_BufSize1);
    #endif // USART
	
    #ifdef CAN
    __HAL_CAN_ENABLE_IT(&CAN_Handler1, CAN_IT_RX_FIFO0_MSG_PENDING);
    #endif // CAN

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
    if(huart == &Usart_Handler1)
    {   
        HAL_UART_Receive_IT(&Usart_Handler1, Usart_Handler1_Buf, Usart_BufSize1);
    }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if(htim == &TimerBase_Handler)
    {
    }

}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan == &CAN_Handler1)
    {
    }
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan == &CAN_Handler1)
    {
    }
}

