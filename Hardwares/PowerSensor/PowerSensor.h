//
// Created by yekai on 2021/7/19.
//

#ifndef SIZEMETER_POWERSENSOR_H
#define SIZEMETER_POWERSENSOR_H

#include "stdint.h"

enum shape {
    circle, rect, tri
};

enum color {
    blue, green, red
};

typedef struct {
    enum shape shape;
    enum color color;
    uint16_t pixel;
} PS_Pack;

void PS_UartHandler();

void PS_GetShapeAndArea();

void PS_Task();

extern PS_Pack obj;

#endif //SIZEMETER_POWERSENSOR_H
