//
// Created by yekai on 2021/7/19.
//

#include <stdio.h>
#include "PowerSensor.h"
#include "usart.h"
#include "stdbool.h"
#include "string.h"

PS_Pack obj;

bool PS_Busy = false;

uint8_t PS_UartByte;

void PS_UartHandler() {
    static bool receivingFlag = false;
    static uint8_t PS_UartBuffer[30] = {0};
    static uint8_t len = 0;
    if (!receivingFlag) {
        if (PS_UartByte == '(') {
            receivingFlag = true;
        }
    } else {
        if (PS_UartByte != ')') {
            PS_UartBuffer[len] = PS_UartByte;
            len++;
        } else {
            obj.color = PS_UartBuffer[0];
            obj.shape = PS_UartBuffer[2];
            obj.pixel = (PS_UartBuffer[4] << 8) + PS_UartBuffer[5];

            memset(PS_UartBuffer, 0, sizeof(PS_UartBuffer));
            len = 0;
            receivingFlag = false;
            PS_Busy = false;
            return;
        }
    }
    HAL_UART_Receive_IT(&huart3, &PS_UartByte, 1);
}

void PS_GetShapeAndArea() {
    static uint8_t cnt = 0;
    if (PS_Busy) {
        return;
    } else {
        PS_Busy = true;
        HAL_UART_Receive_IT(&huart3, &PS_UartByte, 1);
//        printf("%d\r\n", (int) err);
    }
}
