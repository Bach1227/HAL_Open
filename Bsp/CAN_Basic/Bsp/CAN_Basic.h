#ifndef __CAN_Basic_H
#define __CAN_Basic_H

#include "stm32f1xx_hal.h"
#include "can.h"

void CAN_Init(void);
void CAN_Transmit_STD(uint32_t ID, uint8_t* data, uint8_t len);
void CAN_Transmit_EXT(uint32_t ID, uint8_t* data, uint8_t Len);
uint8_t RxFifoX_IsEmpty(uint32_t RxFifo);
void CAN_FilterBank0Init(void);

#endif // !__CAN_HANDLER_H
