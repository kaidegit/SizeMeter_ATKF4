//
// Created by yekai on 2021/7/19.
//

#ifndef SIZEMETER_TOF_H
#define SIZEMETER_TOF_H

#include "stdint.h"
#include "stdbool.h"

void TOF_UartHandler();

uint16_t TOF_GetDistance();

extern uint16_t distance;
extern bool TOF_Busy;

#endif //SIZEMETER_TOF_H
