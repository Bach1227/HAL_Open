#ifndef __TRIGONOMETRIC_H
#define __TRIGONOMETRIC_H

#define pi 3.141592653f

#include "math.h"
#include "stm32f1xx_hal.h"

float ToRad(float degree);
float ToDegree(float);
float LinearInterpolation_sin(float angle);
float LinearInterpolation_cos(float angle);
float LinearInterpolation_tan(float angle);

#endif // !__TRIGONOMETRIC_
