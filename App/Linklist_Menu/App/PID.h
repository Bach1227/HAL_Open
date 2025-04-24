#ifndef __PID_H
#define __PID_H

#include "stm32f1xx_hal.h"
#include "math.h"

typedef struct
{
    float Kp;
    float Ki;
    float Kd;

    int32_t Target;
    int32_t ValueNow;
    int32_t ValueLast;
    int32_t ErrorNow;
    int32_t ErrorSum;

    int32_t IntegralRange;
    int32_t IntegralLimit;

    int32_t Output;

}PID_Param_int32;

typedef struct
{
    float Kp;
    float Ki;
    float Kd;

    float Target;
    float ValueNow;
    float ValueLast;
    float ErrorNow;
    float ErrorSum;

    float IntegralRange;
    float IntegralLimit;

    float Output;

}PID_Param_float;

void PID_Set_Kparam_int32(PID_Param_int32* PID_Param, float Kp, float Ki, float Kd);
void PID_Set_Kparam_float(PID_Param_float* PID_Param, float Kp, float Ki, float Kd);
void PID_Set_Integral_int32(PID_Param_int32* PID_Param, int32_t Range, int32_t Limit);
void PID_Set_Integral_float(PID_Param_int32* PID_Param, float Range, float Limit);
void PID_Set_Target_int32(PID_Param_int32* PID_Param, int32_t Target);
void PID_Set_Target_float(PID_Param_float* PID_Param, float Target);
int32_t PID_Update_int32(PID_Param_int32* PID_Param, int32_t ValueNow);
float PID_Update_float(PID_Param_float* PID_Param, float ValueNow);



#endif // !__PID_H
