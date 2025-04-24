#ifndef __AT24CXX_H
#define __AT24CXX_H

#include "stm32f1xx_hal.h"
#include "i2c.h"


#define AT24Cxx_DeviceAddress               0xA0
#define AT24Cxx_PageSize                    0x4F

#define AT24C256

#ifdef AT24C256

    #define AT24Cxx_PageNum                 0x2FF

#endif // AT24C256

void AT24Cxx_Write(uint16_t u16Address, uint8_t* u8Data, uint8_t Len);
void AT24Cxx_Read(uint16_t u16Address, uint8_t* u8Data, uint8_t Len);

#endif // !__AT24Cxx_H
