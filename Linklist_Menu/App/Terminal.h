#ifndef __TERMINAL_H
#define __TERMINAL_H

#include "stm32f1xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

typedef void (*Terminal_Fuction)();

typedef struct Terminal_LinkedNode
{
    char Infomation[32];
    Terminal_Fuction Fuction;
    // uint32_t         Argument;
    struct Terminal_LinkedNode* Up_LinkedNode;
    struct Terminal_LinkedNode* Down_LinkedNode;
    struct Terminal_LinkedNode* Prior_LinkedNode;
    struct Terminal_LinkedNode* Next_LinkedNode;
}Terminal_LinkedNode;

typedef enum
{
    LinkedList_NextExisted  = 0,
    LinkedList_OK = 1
}Terminal_LinkedStatus;


#define MAX_ListDepth 10
#define MAX_ListWidth 10

Terminal_LinkedNode* Terminal_LinkedList_InsertToLower(Terminal_LinkedNode* UpperLinkedList, char* Info, void* Fuction);
Terminal_LinkedNode* Terminal_LinkedList_InsertToLowest(Terminal_LinkedNode* UpperLinkedList, char* Info, void* Fuction);
Terminal_LinkedNode* Terminal_LinkedList_InsertToEnd(Terminal_LinkedNode* PriorLinkedList, char* Info, void* Fuction);
void Terminal_LinkedList_UpDown_Traverse(Terminal_LinkedNode* Start_LinkedList);
void Command_Input(uint8_t Cmd);
void OTA_StartUp(void);
void Command_Input(uint8_t Cmd);
void First_Terminal_Test(void);


#endif // !__TERMINAL_H
