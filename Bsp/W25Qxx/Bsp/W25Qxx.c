#include "W25Qxx.h"

static uint8_t Read_UIDCmd[6] = {0x4B, 0x00, 0x00, 0x00, 0x00, 0x00};
static uint8_t UIDArray[6];

static uint8_t Write_EnabelCmd = 0x06;


void W25Q64_Select(void)
{
    HAL_GPIO_WritePin(W25Qxx_CS_GPIO_Port, W25Qxx_CS_Pin, GPIO_PIN_RESET);
}

void W25Q64_Unselect(void)
{
    HAL_GPIO_WritePin(W25Qxx_CS_GPIO_Port, W25Qxx_CS_Pin, GPIO_PIN_SET);
}

uint8_t W25Q64_ReadRegister(uint8_t Reg)
{
    uint8_t Register = (Reg == 1) ? 0x05 : 0x35;
    uint8_t Read_ReadRegisterCmd[2] = 
    {
        Register,
        0xFF
    };
    uint8_t StatusRegisterValueBuffer[2];

    W25Q64_Select();
    HAL_SPI_Transmit(&hspi1, Read_ReadRegisterCmd, 2, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, StatusRegisterValueBuffer, 2, HAL_MAX_DELAY);
    W25Q64_Unselect();

    return StatusRegisterValueBuffer[1];
}

void W25Q64_WaitForReady(void)
{
    while(W25Q64_ReadRegister(1) & 0x01)
    {

    }
}

void W25Q64_WriteEnable(void)
{
    W25Q64_Select();
    HAL_SPI_Transmit(&hspi1, &Write_EnabelCmd, 1, HAL_MAX_DELAY);
    W25Q64_Unselect();
}

uint32_t W25Q64_ReadUID(void)
{
    W25Q64_Select();
    HAL_SPI_Transmit(&hspi1, Read_UIDCmd, 6, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, UIDArray, 6, HAL_MAX_DELAY);
    W25Q64_Unselect();
    return UIDArray[5];
}

void W25Q64_EraseSector(uint32_t Address)
{
    uint8_t Write_EraseSectorCmd[4] = 
    {
        0x20,
        (uint8_t)(Address >> 16),
        (uint8_t)(Address >> 8),
        (uint8_t)(Address)
    };
    
    W25Q64_WriteEnable();
    W25Q64_WaitForReady();

    W25Q64_Select();
    HAL_SPI_Transmit(&hspi1, Write_EraseSectorCmd, 4, HAL_MAX_DELAY);
    W25Q64_Unselect();

    W25Q64_WaitForReady();
}

void W25Q64_ReadData(uint8_t* Buffer, uint32_t Address, uint16_t Len)
{
    uint8_t Read_ReadDataCmd[5] =
    {
        0x03,
        (uint8_t)(Address >> 16),
        (uint8_t)(Address >> 8),
        (uint8_t)(Address),
    };

    W25Q64_WaitForReady();

    W25Q64_Select();
    HAL_SPI_Transmit(&hspi1, Read_ReadDataCmd, 4, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, Buffer, Len, HAL_MAX_DELAY);
    W25Q64_Unselect();

    W25Q64_WaitForReady();
}

void W25Q64_PageProgram(uint32_t Address, uint8_t* Data, uint16_t Len)
{
    uint8_t Write_PageProgramCmd[4] = 
    {
        0x02,
        (uint8_t)(Address >> 16),
        (uint8_t)(Address >> 8),
        (uint8_t)(Address),
    };

    W25Q64_WriteEnable();
    W25Q64_WaitForReady();
    
    W25Q64_Select();
    HAL_SPI_Transmit(&hspi1, Write_PageProgramCmd, 4, HAL_MAX_DELAY);
    HAL_SPI_Transmit(&hspi1, Data, Len, HAL_MAX_DELAY);
    W25Q64_Unselect();

    W25Q64_WaitForReady();
}
