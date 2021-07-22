//
// Created by yekai on 2021/7/21.
//

#include "StepMotor.h"
#include "stdbool.h"
#include "tim.h"

bool movingFlag = false;

void Lmotor_TurnAngle(int angle) {
    if (!movingFlag) {
        if (angle > 0) {
            movingFlag = true;
            uint16_t tick = angle * 3200 / 360;
            // 设定转向
            HAL_GPIO_WritePin(L_MOTOR_DIR_GPIO_Port, L_MOTOR_DIR_Pin, GPIO_PIN_RESET);
            // 开始转动
            HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);
            // 设定转动时长
            __HAL_TIM_SET_AUTORELOAD(&htim11, tick * 10);
            __HAL_TIM_SET_COUNTER(&htim11, 0);
            HAL_TIM_Base_Start_IT(&htim11);
        } else {
            movingFlag = true;
            uint16_t tick = -angle * 3200 / 360;
            // 设定转向
            HAL_GPIO_WritePin(L_MOTOR_DIR_GPIO_Port, L_MOTOR_DIR_Pin, GPIO_PIN_SET);
            // 开始转动
            HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);
            // 设定转动时长
            __HAL_TIM_SET_AUTORELOAD(&htim11, tick * 10);
            __HAL_TIM_SET_COUNTER(&htim11, 0);
            HAL_TIM_Base_Start_IT(&htim11);
        }
    }
}

void Hmotor_TurnAngle(int angle) {
    if (!movingFlag) {
        if (angle > 0) {
            movingFlag = true;
            uint16_t tick = angle * 3200 / 360;
            // 设定转向
            HAL_GPIO_WritePin(H_MOTOR_DIR_GPIO_Port,H_MOTOR_DIR_Pin, GPIO_PIN_RESET);
            // 开始转动
            HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_4);
            // 设定转动时长
            __HAL_TIM_SET_AUTORELOAD(&htim11, tick * 10);
            __HAL_TIM_SET_COUNTER(&htim11, 0);
            HAL_TIM_Base_Start_IT(&htim11);
        } else {
            movingFlag = true;
            uint16_t tick = -angle * 3200 / 360;
            // 设定转向
            HAL_GPIO_WritePin(H_MOTOR_DIR_GPIO_Port, H_MOTOR_DIR_Pin, GPIO_PIN_SET);
            // 开始转动
            HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_4);
            // 设定转动时长
            __HAL_TIM_SET_AUTORELOAD(&htim11, tick * 10);
            __HAL_TIM_SET_COUNTER(&htim11, 0);
            HAL_TIM_Base_Start_IT(&htim11);
        }
    }
}

void Motor_StopAll() {
    movingFlag = false;
    HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_3);
    HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_4);
    HAL_TIM_Base_Stop(&htim11);
}

void Motor_Init() {
    HAL_GPIO_WritePin(H_MOTOR_EN_GPIO_Port, H_MOTOR_EN_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(L_MOTOR_EN_GPIO_Port, L_MOTOR_EN_Pin, GPIO_PIN_RESET);
    __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_3, 100);
    __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_4, 100);
}
