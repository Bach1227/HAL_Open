#include "PID.h"

void PID_Set_Kparam_int32(PID_Param_int32* PID_Param, float Kp, float Ki, float Kd)
{
    PID_Param->Kp = Kp;
    PID_Param->Ki = Ki;
    PID_Param->Kd = Kd;
}

void PID_Set_Kparam_float(PID_Param_float* PID_Param, float Kp, float Ki, float Kd)
{
    PID_Param->Kp = Kp;
    PID_Param->Ki = Ki;
    PID_Param->Kd = Kd;
}

void PID_Set_Integral_int32(PID_Param_int32* PID_Param, int32_t Range, int32_t Limit)
{
    PID_Param->IntegralRange = Range;
    PID_Param->IntegralLimit = Limit;
}

void PID_Set_Integral_float(PID_Param_int32* PID_Param, float Range, float Limit)
{
    PID_Param->IntegralRange = Range;
    PID_Param->IntegralLimit = Limit;
}

void PID_Set_Target_int32(PID_Param_int32* PID_Param, int32_t Target)
{
    PID_Param->Target = Target;
}

void PID_Set_Target_float(PID_Param_float* PID_Param, float Target)
{
    PID_Param->Target = Target;
}

int32_t PID_Update_int32(PID_Param_int32* PID_Param, int32_t ValueNow)
{
    PID_Param->ValueNow = ValueNow;
    PID_Param->ErrorNow = PID_Param->Target - PID_Param->ValueNow;

    if (abs(PID_Param->ErrorNow) <= PID_Param->IntegralRange)
    {
        PID_Param->ErrorSum += PID_Param->ErrorNow;
    }

    if (abs(PID_Param->ErrorSum) <= PID_Param->IntegralLimit)
    {
        PID_Param->ErrorSum = PID_Param->IntegralLimit;
    }
    

    PID_Param->Output = PID_Param->Kp * PID_Param->ValueNow
                      + PID_Param->Ki * PID_Param->ErrorSum
                      + PID_Param->Kd * (PID_Param->ValueNow - PID_Param->ValueLast);
                      
    return PID_Param->Output;
}

float PID_Update_float(PID_Param_float* PID_Param, float ValueNow)
{
    PID_Param->ValueNow = ValueNow;
    PID_Param->ErrorNow = PID_Param->Target - PID_Param->ValueNow;

    if (fabs(PID_Param->ErrorNow) <= PID_Param->IntegralRange)
    {
        PID_Param->ErrorSum += PID_Param->ErrorNow;
    }

    if (fabs(PID_Param->ErrorSum) <= PID_Param->IntegralLimit)
    {
        PID_Param->ErrorSum = PID_Param->IntegralLimit;
    }
    

    PID_Param->Output = PID_Param->Kp * PID_Param->ValueNow
                      + PID_Param->Ki * PID_Param->ErrorSum
                      + PID_Param->Kd * (PID_Param->ValueNow - PID_Param->ValueLast);

    return PID_Param->Output;
}
