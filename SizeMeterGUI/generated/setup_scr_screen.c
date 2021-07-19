/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write codes screen_btn_1
	ui->screen_btn_1 = lv_btn_create(ui->screen, NULL);

	//Write style LV_BTN_PART_MAIN for screen_btn_1
	static lv_style_t style_screen_btn_1_main;
	lv_style_init(&style_screen_btn_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_1_main
	lv_style_set_radius(&style_screen_btn_1_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_btn_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_btn_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_btn_1, LV_BTN_PART_MAIN, &style_screen_btn_1_main);
	lv_obj_set_pos(ui->screen_btn_1, 135, 105);
	lv_obj_set_size(ui->screen_btn_1, 100, 50);
	ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1, NULL);
	lv_label_set_text(ui->screen_btn_1_label, "default");
	lv_obj_set_style_local_text_color(ui->screen_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_12);
}