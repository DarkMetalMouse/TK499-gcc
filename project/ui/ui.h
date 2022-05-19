// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SRS_Programmer

#ifndef _SRS_PROGRAMMER_UI_H
#define _SRS_PROGRAMMER_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

extern lv_obj_t * ui_MainScreen;
extern lv_obj_t * ui_HeaderPanel;
extern lv_obj_t * ui_ConnectionLabel;
extern lv_obj_t * ui_RightAngleArc;
extern lv_obj_t * ui_RightAngleLabel;
extern lv_obj_t * ui_RightAngleTextArea;
extern lv_obj_t * ui_LeftAngleArc;
extern lv_obj_t * ui_LeftAngleLabel;
extern lv_obj_t * ui_RightAngleTextArea1;
extern lv_obj_t * ui_ModePanel;
extern lv_obj_t * ui_ModeSwitch;
extern lv_obj_t * ui_ContinousModeLabel;
extern lv_obj_t * ui_ServoModeLabel;
extern lv_obj_t * ui_GetAngleLeftButton;
extern lv_obj_t * ui_GetAngleLeftLabel;
extern lv_obj_t * ui_GetAngleRightButton;
extern lv_obj_t * ui_GetAngleRgihtLabel;
extern lv_obj_t * ui_ProgramButton;
extern lv_obj_t * ui_ProgramButtonLabel;
extern lv_obj_t * ui_PWMArc;
extern lv_obj_t * ui_PWMLabel;
extern lv_obj_t * ui_SwipeTestButton;
extern lv_obj_t * ui_SwipeTestLabel;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_ReadConfigurationButton;
extern lv_obj_t * ui_ReadConfigurationLabel;
extern lv_obj_t * ui_PWMControlButton;
extern lv_obj_t * ui_PWMControlLabel;

void set_left_angle_from_servo(lv_event_t * e);
void set_right_angle_from_servo(lv_event_t * e);
void program_servo(lv_event_t * e);
void set_pwm(lv_event_t * e);
void start_swipe_test(lv_event_t * e);
void read_configuration(lv_event_t * e);
void pwm_clicked(lv_event_t * e);





void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
