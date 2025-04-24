#include "AT24Cxx.h"

void AT24Cxx_Write(uint16_t u16Address, uint8_t* u8Data, uint8_t Len)
{
    if(Len > AT24Cxx_PageSize)
    {
        Len = AT24Cxx_PageSize;
    }
    HAL_I2C_Mem_Write(&hi2c1, AT24Cxx_DeviceAddress, u16Address, I2C_MEMADD_SIZE_16BIT, u8Data, Len, HAL_MAX_DELAY);
}

void AT24Cxx_Read(uint16_t u16Address, uint8_t* u8Data, uint8_t Len)
{
    if(Len > AT24Cxx_PageSize)
    {
        Len = AT24Cxx_PageSize;
    }
    HAL_I2C_Mem_Read(&hi2c1, AT24Cxx_DeviceAddress, u16Address, I2C_MEMADD_SIZE_16BIT, u8Data, Len, HAL_MAX_DELAY);
}
