#ifndef __W25Qxx_H
#define __W25Qxx_H

#include "stm32f1xx_hal.h"
#include "spi.h"
#include "gpio.h"

#define W25Q64_Size                         0x800000
#define W25Q32_Size                         0x400000
#define W25Qxx_BlockSize                    0x10000
#define W25Qxx_SectorSize                   0x1000
#define W25Qxx_PageSize                     0x100 

uint32_t W25Q64_ReadUID(void);
uint8_t W25Q64_ReadRegister(uint8_t Reg);
void W25Q64_WriteEnable(void);
void W25Q64_EraseSector(uint32_t Address);
void W25Q64_PageProgram(uint32_t Address, uint8_t* Data, uint16_t Len);
void W25Q64_ReadData(uint8_t* Buffer, uint32_t Address, uint16_t Len);

#endif // !__W25Q64_H
