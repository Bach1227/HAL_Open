#include "CAN_Basic.h"

/*
CAN_FilterTypeDef FilterArray[14];

void CAN_FilterStructureInit(CAN_FilterTypeDef* FilterSturcture)
{
    FilterSturcture->FilterActivation = CAN_FILTER_ENABLE;
    FilterSturcture->FilterBank = 
}

void CAN_FilterInit(uint8_t FilterBank_x, CAN_FilterTypeDef* FilterStucture)
{
    switch (FilterBank_x)
    {
    case 0:

        break;
    
    default:

        break;
    }
}
*/

                                                                      

void CAN_Init(void)
{
    #ifdef STM32F1
    HAL_CAN_Start(&hcan);
    #endif

    #ifdef STM32F4
    HAL_CAN_Start(&hcan1);
    HAL_CAN_Start(&hcan2);
    #endif
}

#ifdef STM32F1
void CAN_Transmit_STD(uint32_t ID, uint8_t* data, uint8_t len)
{
    //uint8_t test[3] = {0xA1, 0xBB, 0xCC};
    CAN_TxHeaderTypeDef TxMSG;
    TxMSG.StdId = ID;
    TxMSG.ExtId = 0;
    TxMSG.IDE = CAN_ID_STD;
    TxMSG.RTR = CAN_RTR_DATA;
    TxMSG.DLC = 3;

    uint32_t TxMailbox;

    HAL_CAN_AddTxMessage(&TxMSG, data, &TxMailbox);
}

void CAN_Transmit_EXT(uint32_t ID, uint8_t* data, uint8_t Len)
{
    CAN_TxHeaderTypeDef TxMSG;

    TxMSG.StdId = 0x000;
    TxMSG.ExtId = ID;
    TxMSG.IDE = CAN_ID_EXT;
    TxMSG.RTR = CAN_RTR_DATA;
    TxMSG.DLC = Len;

    uint32_t TxMailbox;
    HAL_CAN_AddTxMessage(&hcan, &TxMSG, data, &TxMailbox);
}

uint8_t RxFifoX_IsEmpty(uint32_t RxFifo)
{
    if (HAL_CAN_GetRxFifoFillLevel(&hcan, RxFifo) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif // STM32F1

#ifdef STM32F4
void CAN_Transmit_STD(CAN_HandleTypeDef* hcan_num, uint32_t ID, uint8_t* data, uint8_t len)
{
    //uint8_t test[3] = {0xA1, 0xBB, 0xCC};
    CAN_TxHeaderTypeDef TxMSG;
    TxMSG.StdId = ID;
    TxMSG.ExtId = 0;
    TxMSG.IDE = CAN_ID_STD;
    TxMSG.RTR = CAN_RTR_DATA;
    TxMSG.DLC = 3;

    uint32_t TxMailbox;

    HAL_CAN_AddTxMessage(hcan_num, &TxMSG, data, &TxMailbox);
}

void CAN_Transmit_EXT(CAN_HandleTypeDef* hcan_num, uint32_t ID, uint8_t* data, uint8_t Len)
{
    CAN_TxHeaderTypeDef TxMSG;

    TxMSG.StdId = 0x000;
    TxMSG.ExtId = ID;
    TxMSG.IDE = CAN_ID_EXT;
    TxMSG.RTR = CAN_RTR_DATA;
    TxMSG.DLC = Len;

    uint32_t TxMailbox;
    HAL_CAN_AddTxMessage(hcan_num, &TxMSG, data, &TxMailbox);
}

uint8_t RxFifoX_IsEmpty(CAN_HandleTypeDef* hcan_num, uint32_t RxFifo)
{
    if (HAL_CAN_GetRxFifoFillLevel(hcan_num, RxFifo) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif // STM32F4

