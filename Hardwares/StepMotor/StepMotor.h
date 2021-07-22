//
// Created by yekai on 2021/7/21.
//

#ifndef SIZEMETER_ATKF4_STEPMOTOR_H
#define SIZEMETER_ATKF4_STEPMOTOR_H

#include "stdint.h"

void Motor_Init();

void Lmotor_TurnAngle(int angle);

void Hmotor_TurnAngle(int angle);

void Motor_StopAll();

#endif //SIZEMETER_ATKF4_STEPMOTOR_H
