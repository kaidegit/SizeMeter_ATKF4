//
// Created by yekai on 2021/7/19.
//

#include <stdio.h>
#include "PowerSensor.h"
#include "usart.h"
#include "stdbool.h"
#include "string.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "lcd.h"
#include "tof.h"
#include "math.h"

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
    }
}

void PS_Task() {
    static uint8_t temp_shape = 3;
    static uint8_t temp_color = 3;
    PS_GetShapeAndArea();
    if ((obj.shape == 255) || (obj.color == 255)) {
        return;
    }
    if ((temp_color != obj.color) || (temp_shape != obj.shape)) {
        if (temp_color != obj.color) {
            POINT_COLOR = obj.color == 0 ? BLUE : \
                obj.color == 1 ? GREEN : RED;
        }
        LCD_Color_Fill(40, 40, 140, 140, 0xffff);
        if (obj.shape == 0) {                        //圆形
            LCD_Draw_FilledCircle(90, 90, 50);
        } else if (obj.shape == 1) {                 // 正方形
            LCD_Draw_FilledRect(50, 50, 130, 130);
        } else if (obj.shape == 2) {                 // 三角形
            LCD_Draw_FilledRegTriangle(90, 100, 90);
        }
        temp_shape = obj.shape;
        temp_color = obj.color;
    }
    // 根据像素数计算边长
    double s = 225.0 / (2700 * 1000.0) * distance * obj.pixel;
    double a;
    switch (temp_shape) {
        case 0: // 圆形
            a = sqrt(s / 3.14159) * 2;
            break;
        case 1: // 正方形
            a = sqrt(s);
            break;
        case 2: // 三角形
            a = sqrt(4 * s / 1.732);
            break;
        default:
            a = 0;
            break;
    }
    char temp[30];
//    sprintf(temp, "%d.%d", a / 10, a % 10);
    sprintf(temp, "%.3f", a);//a / 10, a % 10);
    lv_label_set_text(guider_ui.screen_label_3, temp);
}