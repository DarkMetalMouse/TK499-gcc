// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SRS_Programmer

#include "ui.h"
#include "srs_programmer.h"
#include "ui_helpers.h"
#include "HAL_conf.h"

void set_arc_and_label(lv_obj_t *arc, lv_obj_t *label, int angle)
{
	if (angle > lv_arc_get_max_value(arc) || angle < lv_arc_get_min_value(arc))
		return;

	char buf[_UI_TEMPORARY_STRING_BUFFER_SIZE];
	lv_snprintf(buf, sizeof(buf), "%d", angle);

	lv_label_set_text(label, buf);
	lv_arc_set_value(arc, angle);
}

void set_right_angle_from_servo(lv_event_t *e)
{
	set_arc_and_label(ui_RightAngleArc, ui_RightAngleLabel, get_angle());
}

void program_servo(lv_event_t *e)

{
	if (lv_obj_has_state(ui_ModeSwitch, LV_STATE_CHECKED))
	{
		program_continuos();
	}
	else
	{
		program_servo_angles(lv_arc_get_value(ui_LeftAngleArc), lv_arc_get_value(ui_RightAngleArc));
	}
}

void set_left_angle_from_servo(lv_event_t *e)
{
	set_arc_and_label(ui_LeftAngleArc, ui_LeftAngleLabel, get_angle());
}

void keyboard_key_pressed(lv_event_t *e)
{
	// Your code here
}

void start_swipe_test(lv_event_t *e)
{
	// Your code here
}

void read_configuration(lv_event_t *e)
{
	// Your code here
}

void set_pwm(lv_event_t *e)
{
	set_pwm_output(map(lv_arc_get_value(ui_PWMArc), -100, 500, 100, 2500));
}
