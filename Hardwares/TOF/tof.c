//
// Created by yekai on 2021/7/19.
//

#include "tof.h"
#include "usart.h"
#include "string.h"

const uint8_t TOF_Command[] = {0XA5, 0X15, 0XBA};

uint16_t distance;
bool TOF_Busy;

uint8_t TOF_UartByte;

void TOF_UartHandler() {
    static uint8_t state = 0;
    static uint8_t tofBuf[8] = {0};
    switch (state) {
        case 0: // 帧头标志
            if (TOF_UartByte == 0x5a) {
                tofBuf[state] = TOF_UartByte;
                state++;
            }
            break;
        case 1: // 帧头标志
            if (TOF_UartByte == 0x5a) {
                tofBuf[state] = TOF_UartByte;
                state++;
            } else {
                state = 0;
            }
            break;
        case 2: // 本帧数据类型
        case 3: // 数据量
        case 4: // 数据前高 8 位
        case 5: // 数据前低 8 位
        case 6: // 模块测量模式
            tofBuf[state] = TOF_UartByte;
            state++;
            break;
        case 7: // 校验和
            tofBuf[state] = TOF_UartByte;
            uint16_t sum = 0;
            for (uint8_t i = 0; i < 7; i++) {
                sum += tofBuf[i];
            }
            if ((sum & 0xff) != TOF_UartByte) {
                distance = -1;
            } else {
                distance = (tofBuf[4] << 8) | tofBuf[5];
            }
            TOF_Busy = false;
            memset(tofBuf, 0, sizeof(tofBuf));
            state = 0;
            return;
            break;
        default:
            break;
    }
    HAL_UART_Receive_IT(&huart2, &TOF_UartByte, 1);
}

uint16_t TOF_GetDistance() {
    uint16_t cnt = 1;
    TOF_Busy = true;
    HAL_UART_Transmit(&huart2, (uint8_t *) TOF_Command, 3, 0xff);
    HAL_UART_Receive_IT(&huart2, &TOF_UartByte, 1);
    while (TOF_Busy && (cnt++ < 10000));
    return distance;
}
