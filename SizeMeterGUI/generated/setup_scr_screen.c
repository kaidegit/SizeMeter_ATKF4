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

	//Write codes screen_lmeter_1
	ui->screen_lmeter_1 = lv_linemeter_create(ui->screen, NULL);

	//Write style LV_LINEMETER_PART_MAIN for screen_lmeter_1
	static lv_style_t style_screen_lmeter_1_main;
	lv_style_init(&style_screen_lmeter_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_lmeter_1_main
	lv_style_set_radius(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 1);
	lv_style_set_bg_color(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_line_color(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_line_width(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 4);
	lv_style_set_line_opa(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_scale_grad_color(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_scale_end_color(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_scale_width(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 10);
	lv_style_set_scale_end_line_width(&style_screen_lmeter_1_main, LV_STATE_DEFAULT, 4);
	lv_obj_add_style(ui->screen_lmeter_1, LV_LINEMETER_PART_MAIN, &style_screen_lmeter_1_main);
	lv_obj_set_pos(ui->screen_lmeter_1, 176, 68);
	lv_obj_set_size(ui->screen_lmeter_1, 120, 120);
	lv_linemeter_set_scale(ui->screen_lmeter_1, 300, 35);
	lv_linemeter_set_range(ui->screen_lmeter_1, 0, 3500);
	lv_linemeter_set_value(ui->screen_lmeter_1, 100);
	lv_linemeter_set_angle_offset(ui->screen_lmeter_1, 0);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_1, "距离");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_1
	static lv_style_t style_screen_label_1_main;
	lv_style_init(&style_screen_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_1_main
	lv_style_set_radius(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_1, LV_LABEL_PART_MAIN, &style_screen_label_1_main);
	lv_obj_set_pos(ui->screen_label_1, 185, 25);
	lv_obj_set_size(ui->screen_label_1, 100, 0);

	//Write codes screen_distance
	ui->screen_distance = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_distance, "default");
	lv_label_set_long_mode(ui->screen_distance, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_distance, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_distance
	static lv_style_t style_screen_distance_main;
	lv_style_init(&style_screen_distance_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_distance_main
	lv_style_set_radius(&style_screen_distance_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_distance_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_distance_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_distance_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_distance_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_distance_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_distance_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_distance_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_distance_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_distance_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_distance_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_distance_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_distance, LV_LABEL_PART_MAIN, &style_screen_distance_main);
	lv_obj_set_pos(ui->screen_distance, 204, 124);
	lv_obj_set_size(ui->screen_distance, 67, 0);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_2, "边长");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_2, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_2
	static lv_style_t style_screen_label_2_main;
	lv_style_init(&style_screen_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_2_main
	lv_style_set_radius(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_2_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_2, LV_LABEL_PART_MAIN, &style_screen_label_2_main);
	lv_obj_set_pos(ui->screen_label_2, 15, 191);
	lv_obj_set_size(ui->screen_label_2, 43, 0);

	//Write codes screen_label_3
	ui->screen_label_3 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_3, "default");
	lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_3, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_3
	static lv_style_t style_screen_label_3_main;
	lv_style_init(&style_screen_label_3_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_3_main
	lv_style_set_radius(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_3_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_3_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_3_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_3, LV_LABEL_PART_MAIN, &style_screen_label_3_main);
	lv_obj_set_pos(ui->screen_label_3, 69, 192);
	lv_obj_set_size(ui->screen_label_3, 100, 0);
}