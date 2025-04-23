#include "Terminal.h"

char Current_Cmd[100];
Terminal_LinkedNode Terminal_TestRootNode = {"Root Terminal", NULL, NULL, NULL, NULL, NULL};
Terminal_Fuction FunctionList[10];

void Command_Input(uint8_t Cmd)
{
    switch (Cmd)
    {
    case 0:
        if(FunctionList[0] != NULL) FunctionList[0]();
        break;
    
    case 1:
        if(FunctionList[1] != NULL) FunctionList[1]();
        break;
    
    case 2:
        if(FunctionList[2] != NULL) FunctionList[2]();
        break;
    
    case 3:
        if(FunctionList[3] != NULL) FunctionList[3]();
        break;
    
    case 4:
        if(FunctionList[4] != NULL) FunctionList[4]();
        break;
    
    default:
        break;
    }
}

Terminal_LinkedNode* Terminal_LinkedList_InsertToNext(Terminal_LinkedNode* PriorLinkedList, 
    char* Info, void* Fuction)
{
    Terminal_LinkedNode* NewLinkedNode = (Terminal_LinkedNode*)malloc(sizeof(Terminal_LinkedNode));
    PriorLinkedList->Next_LinkedNode = NewLinkedNode;
    NewLinkedNode->Prior_LinkedNode = PriorLinkedList;
    memcpy(NewLinkedNode->Infomation, Info, 32);
    NewLinkedNode->Fuction = (Terminal_Fuction)Fuction;
    return NewLinkedNode;
}

Terminal_LinkedNode* Terminal_LinkedList_InsertToEnd(Terminal_LinkedNode* PriorLinkedList, 
                                        char* Info, void* Fuction)
{
    Terminal_LinkedNode* NewLinkedList = (Terminal_LinkedNode*)malloc(sizeof(Terminal_LinkedNode));
    Terminal_LinkedNode* Temp = PriorLinkedList;
    while (Temp->Next_LinkedNode != NULL)
    {
        Temp = Temp->Next_LinkedNode;
    }
    Temp->Next_LinkedNode = NewLinkedList;
    NewLinkedList->Prior_LinkedNode = Temp;
    memcpy(NewLinkedList->Infomation, Info, 32);
    NewLinkedList->Fuction = (Terminal_Fuction)Fuction;
    return NewLinkedList;
}

Terminal_LinkedNode* Terminal_LinkedList_InsertToLower(Terminal_LinkedNode* UpperLinkedList, 
    char* Info, void* Fuction)
{
    Terminal_LinkedNode* NewLinkedList = (Terminal_LinkedNode*)malloc(sizeof(Terminal_LinkedNode));
    UpperLinkedList->Down_LinkedNode = NewLinkedList;
    NewLinkedList->Up_LinkedNode = UpperLinkedList;
    memcpy(NewLinkedList->Infomation, Info, 32);
    NewLinkedList->Fuction = (Terminal_Fuction)Fuction;
    return NewLinkedList;
}

Terminal_LinkedNode* Terminal_LinkedList_InsertToLowest(Terminal_LinkedNode* UpperLinkedList, 
                                        char* Info, void* Fuction)
{
    Terminal_LinkedNode* NewLinkedList = (Terminal_LinkedNode*)malloc(sizeof(Terminal_LinkedNode));
    Terminal_LinkedNode* Temp = UpperLinkedList;
    while (Temp->Down_LinkedNode != NULL)
    {
        Temp = Temp->Down_LinkedNode;
    }
    Temp->Down_LinkedNode = NewLinkedList;
    NewLinkedList->Up_LinkedNode = Temp;
    memcpy(NewLinkedList->Infomation, Info, 32);
    NewLinkedList->Fuction = (Terminal_Fuction)Fuction;
    return NewLinkedList;
}

void Terminal_LinkedList_UpDown_Traverse(Terminal_LinkedNode* Start_LinkedList)
{
    Terminal_LinkedNode* Current_Terminal_LinkedNode = Start_LinkedList;
    uint8_t i = 0;
    while (Current_Terminal_LinkedNode->Down_LinkedNode != NULL)
    {
        printf("%s\n", Current_Terminal_LinkedNode->Infomation);
        if (i < 9)
        {
            FunctionList[i++] = Current_Terminal_LinkedNode->Fuction;
            Current_Terminal_LinkedNode = Current_Terminal_LinkedNode->Down_LinkedNode;
        }
    }
    FunctionList[i++] = Current_Terminal_LinkedNode->Fuction;
    printf("%s\n", Current_Terminal_LinkedNode->Infomation);
    // Current_Terminal_LinkedNode = Current_Terminal_LinkedNode->Next_LinkedNode;
}

void Terminal_LinkedList_Deepin_Traverse(Terminal_LinkedNode* Start_LinkedList)
{
    Terminal_LinkedNode* Current_Terminal_LinkedNode = Start_LinkedList;
    while (Current_Terminal_LinkedNode->Next_LinkedNode != NULL)
    {
        printf("%s\n", Current_Terminal_LinkedNode->Infomation);
        Current_Terminal_LinkedNode = Current_Terminal_LinkedNode->Next_LinkedNode;
    }
    printf("%s\n", Current_Terminal_LinkedNode->Infomation);
    // Current_Terminal_LinkedNode = Current_Terminal_LinkedNode->Next_LinkedNode;
}

void pa(void)
{
    printf("AAAA\n");
}
void pb(void)
{
    printf("B\n");
}
void pc(void)
{
    printf("C\n");
}

void Second_Terminal_Test(void)
{
    static Terminal_LinkedNode Terminal_TestRootNode = {"Second Terminal", NULL, NULL, NULL, NULL, NULL};
    Terminal_LinkedNode* Test_1_1 = Terminal_LinkedList_InsertToLowest(&Terminal_TestRootNode, "[1]:2_1", pa);
    Terminal_LinkedNode* Test_1_2 = Terminal_LinkedList_InsertToLowest(&Terminal_TestRootNode, "[2]:2_2", pb);
    Terminal_LinkedNode* Test_1_3 = Terminal_LinkedList_InsertToLowest(&Terminal_TestRootNode, "[3]:2_3", pc);
    Terminal_LinkedList_UpDown_Traverse(&Terminal_TestRootNode);
}

void First_Terminal_Test(void)
{
    Terminal_LinkedNode* Test_1_1 = Terminal_LinkedList_InsertToLowest(&Terminal_TestRootNode, "[1]:1_1", pa);
    Terminal_LinkedNode* Test_1_2 = Terminal_LinkedList_InsertToLowest(&Terminal_TestRootNode, "[2]:1_2", pb);
    Terminal_LinkedNode* Test_1_3 = Terminal_LinkedList_InsertToLowest(&Terminal_TestRootNode, "[3]:1_3", pc);
    Terminal_LinkedList_UpDown_Traverse(&Terminal_TestRootNode);
}



