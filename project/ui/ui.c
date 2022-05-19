// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SRS_Programmer

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_MainScreen;
lv_obj_t * ui_HeaderPanel;
lv_obj_t * ui_ConnectionLabel;
lv_obj_t * ui_RightAngleArc;
lv_obj_t * ui_RightAngleLabel;
lv_obj_t * ui_RightAngleTextArea;
lv_obj_t * ui_LeftAngleArc;
lv_obj_t * ui_LeftAngleLabel;
lv_obj_t * ui_RightAngleTextArea1;
lv_obj_t * ui_ModePanel;
lv_obj_t * ui_ModeSwitch;
lv_obj_t * ui_ContinousModeLabel;
lv_obj_t * ui_ServoModeLabel;
lv_obj_t * ui_GetAngleLeftButton;
lv_obj_t * ui_GetAngleLeftLabel;
lv_obj_t * ui_GetAngleRightButton;
lv_obj_t * ui_GetAngleRgihtLabel;
lv_obj_t * ui_ProgramButton;
lv_obj_t * ui_ProgramButtonLabel;
lv_obj_t * ui_PWMArc;
lv_obj_t * ui_PWMLabel;
lv_obj_t * ui_SwipeTestButton;
lv_obj_t * ui_SwipeTestLabel;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_ReadConfigurationButton;
lv_obj_t * ui_ReadConfigurationLabel;
lv_obj_t * ui_PWMControlButton;
lv_obj_t * ui_PWMControlLabel;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void ui_event_MainScreen(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_MainScreen, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    }
}
static void ui_event_RightAngleArc(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_RightAngleLabel, ta, "", "");
    }
}
static void ui_event_LeftAngleArc(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_LeftAngleLabel, ta, "", "");
    }
}
static void ui_event_GetAngleLeftButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        set_left_angle_from_servo(e);
    }
}
static void ui_event_GetAngleRightButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        set_right_angle_from_servo(e);
    }
}
static void ui_event_ProgramButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        program_servo(e);
        _ui_state_modify(ui_ProgramButton, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
    }
}
static void ui_event_PWMArc(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_PWMLabel, ta, "", "%");
        set_pwm(e);
    }
}
static void ui_event_SwipeTestButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        start_swipe_test(e);
    }
}
static void ui_event_ReadConfigurationButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        read_configuration(e);
    }
}
static void ui_event_PWMControlButton(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        pwm_clicked(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_MainScreen_screen_init(void)
{

    // ui_MainScreen

    ui_MainScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_MainScreen, ui_event_MainScreen, LV_EVENT_ALL, NULL);

    // ui_HeaderPanel

    ui_HeaderPanel = lv_obj_create(ui_MainScreen);

    lv_obj_set_height(ui_HeaderPanel, 50);
    lv_obj_set_width(ui_HeaderPanel, lv_pct(100));

    lv_obj_set_x(ui_HeaderPanel, 0);
    lv_obj_set_y(ui_HeaderPanel, 0);

    lv_obj_set_align(ui_HeaderPanel, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_HeaderPanel, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_scrollbar_mode(ui_HeaderPanel, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_radius(ui_HeaderPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ConnectionLabel

    ui_ConnectionLabel = lv_label_create(ui_HeaderPanel);

    lv_obj_set_width(ui_ConnectionLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ConnectionLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ConnectionLabel, 0);
    lv_obj_set_y(ui_ConnectionLabel, 0);

    lv_obj_set_align(ui_ConnectionLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ConnectionLabel, "");
    lv_label_set_recolor(ui_ConnectionLabel, "true");

    lv_obj_set_style_text_color(ui_ConnectionLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ConnectionLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ConnectionLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_RightAngleArc

    ui_RightAngleArc = lv_arc_create(ui_MainScreen);

    lv_obj_set_width(ui_RightAngleArc, 240);
    lv_obj_set_height(ui_RightAngleArc, 240);

    lv_obj_set_x(ui_RightAngleArc, lv_pct(20));
    lv_obj_set_y(ui_RightAngleArc, lv_pct(-15));

    lv_obj_set_align(ui_RightAngleArc, LV_ALIGN_CENTER);

    lv_arc_set_range(ui_RightAngleArc, 0, 135);
    lv_arc_set_bg_angles(ui_RightAngleArc, 270, 45);

    lv_obj_add_event_cb(ui_RightAngleArc, ui_event_RightAngleArc, LV_EVENT_ALL, NULL);

    lv_obj_set_style_arc_width(ui_RightAngleArc, 22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_width(ui_RightAngleArc, 22, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_RightAngleLabel

    ui_RightAngleLabel = lv_label_create(ui_RightAngleArc);

    lv_obj_set_width(ui_RightAngleLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_RightAngleLabel, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_RightAngleLabel, 0);
    lv_obj_set_x(ui_RightAngleLabel, lv_pct(0));

    lv_obj_set_align(ui_RightAngleLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_RightAngleLabel, "0");

    lv_obj_add_flag(ui_RightAngleLabel, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_set_style_text_font(ui_RightAngleLabel, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_RightAngleTextArea

    ui_RightAngleTextArea = lv_textarea_create(ui_RightAngleArc);

    lv_obj_set_width(ui_RightAngleTextArea, lv_pct(40));
    lv_obj_set_height(ui_RightAngleTextArea, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_RightAngleTextArea, 0);
    lv_obj_set_y(ui_RightAngleTextArea, 0);

    lv_obj_set_align(ui_RightAngleTextArea, LV_ALIGN_CENTER);

    if("0123456789" == "") lv_textarea_set_accepted_chars(ui_RightAngleTextArea, NULL);
    else lv_textarea_set_accepted_chars(ui_RightAngleTextArea, "0123456789");

    lv_textarea_set_max_length(ui_RightAngleTextArea, 3);
    lv_textarea_set_text(ui_RightAngleTextArea, "0");
    lv_textarea_set_placeholder_text(ui_RightAngleTextArea, "");
    lv_textarea_set_one_line(ui_RightAngleTextArea, true);

    lv_obj_add_flag(ui_RightAngleTextArea, LV_OBJ_FLAG_HIDDEN);

    lv_obj_set_style_text_align(ui_RightAngleTextArea, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RightAngleTextArea, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RightAngleTextArea, lv_color_hex(0x15171A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RightAngleTextArea, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RightAngleTextArea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LeftAngleArc

    ui_LeftAngleArc = lv_arc_create(ui_MainScreen);

    lv_obj_set_width(ui_LeftAngleArc, 240);
    lv_obj_set_height(ui_LeftAngleArc, 240);

    lv_obj_set_x(ui_LeftAngleArc, lv_pct(-20));
    lv_obj_set_y(ui_LeftAngleArc, lv_pct(-15));

    lv_obj_set_align(ui_LeftAngleArc, LV_ALIGN_CENTER);

    lv_arc_set_range(ui_LeftAngleArc, -135, 0);
    lv_arc_set_bg_angles(ui_LeftAngleArc, 135, 270);
    lv_arc_set_mode(ui_LeftAngleArc, LV_ARC_MODE_REVERSE);

    lv_obj_add_event_cb(ui_LeftAngleArc, ui_event_LeftAngleArc, LV_EVENT_ALL, NULL);

    lv_obj_set_style_arc_width(ui_LeftAngleArc, 22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_width(ui_LeftAngleArc, 22, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_LeftAngleLabel

    ui_LeftAngleLabel = lv_label_create(ui_LeftAngleArc);

    lv_obj_set_width(ui_LeftAngleLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LeftAngleLabel, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_LeftAngleLabel, 0);
    lv_obj_set_x(ui_LeftAngleLabel, lv_pct(0));

    lv_obj_set_align(ui_LeftAngleLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LeftAngleLabel, "0");

    lv_obj_add_flag(ui_LeftAngleLabel, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_set_style_text_font(ui_LeftAngleLabel, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_RightAngleTextArea1

    ui_RightAngleTextArea1 = lv_textarea_create(ui_LeftAngleArc);

    lv_obj_set_width(ui_RightAngleTextArea1, lv_pct(40));
    lv_obj_set_height(ui_RightAngleTextArea1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_RightAngleTextArea1, 0);
    lv_obj_set_y(ui_RightAngleTextArea1, 0);

    lv_obj_set_align(ui_RightAngleTextArea1, LV_ALIGN_CENTER);

    if("0123456789" == "") lv_textarea_set_accepted_chars(ui_RightAngleTextArea1, NULL);
    else lv_textarea_set_accepted_chars(ui_RightAngleTextArea1, "0123456789");

    lv_textarea_set_max_length(ui_RightAngleTextArea1, 3);
    lv_textarea_set_text(ui_RightAngleTextArea1, "0");
    lv_textarea_set_placeholder_text(ui_RightAngleTextArea1, "");
    lv_textarea_set_one_line(ui_RightAngleTextArea1, true);

    lv_obj_add_flag(ui_RightAngleTextArea1, LV_OBJ_FLAG_HIDDEN);

    lv_obj_set_style_text_align(ui_RightAngleTextArea1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RightAngleTextArea1, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RightAngleTextArea1, lv_color_hex(0x15171A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RightAngleTextArea1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RightAngleTextArea1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ModePanel

    ui_ModePanel = lv_obj_create(ui_MainScreen);

    lv_obj_set_width(ui_ModePanel, 379);
    lv_obj_set_height(ui_ModePanel, 50);

    lv_obj_set_x(ui_ModePanel, -22);
    lv_obj_set_y(ui_ModePanel, lv_pct(3));

    lv_obj_set_align(ui_ModePanel, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_ModePanel, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_ModePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ModePanel, lv_color_hex(0x15171A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ModePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ModePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ModeSwitch

    ui_ModeSwitch = lv_switch_create(ui_ModePanel);

    lv_obj_set_width(ui_ModeSwitch, 70);
    lv_obj_set_height(ui_ModeSwitch, 35);

    lv_obj_set_x(ui_ModeSwitch, 0);
    lv_obj_set_y(ui_ModeSwitch, 0);

    lv_obj_set_align(ui_ModeSwitch, LV_ALIGN_CENTER);

    // ui_ContinousModeLabel

    ui_ContinousModeLabel = lv_label_create(ui_ModePanel);

    lv_obj_set_width(ui_ContinousModeLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ContinousModeLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ContinousModeLabel, 107);
    lv_obj_set_y(ui_ContinousModeLabel, lv_pct(-5));

    lv_obj_set_align(ui_ContinousModeLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ContinousModeLabel, "Continuous");

    lv_obj_set_style_text_font(ui_ContinousModeLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ServoModeLabel

    ui_ServoModeLabel = lv_label_create(ui_ModePanel);

    lv_obj_set_width(ui_ServoModeLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ServoModeLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ServoModeLabel, -72);
    lv_obj_set_y(ui_ServoModeLabel, lv_pct(3));

    lv_obj_set_align(ui_ServoModeLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ServoModeLabel, "Servo");

    lv_obj_set_style_text_font(ui_ServoModeLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_GetAngleLeftButton

    ui_GetAngleLeftButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_GetAngleLeftButton, 120);
    lv_obj_set_height(ui_GetAngleLeftButton, 60);

    lv_obj_set_x(ui_GetAngleLeftButton, lv_pct(-24));
    lv_obj_set_y(ui_GetAngleLeftButton, lv_pct(-36));

    lv_obj_set_align(ui_GetAngleLeftButton, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_GetAngleLeftButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_GetAngleLeftButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_GetAngleLeftButton, ui_event_GetAngleLeftButton, LV_EVENT_ALL, NULL);

    // ui_GetAngleLeftLabel

    ui_GetAngleLeftLabel = lv_label_create(ui_GetAngleLeftButton);

    lv_obj_set_width(ui_GetAngleLeftLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_GetAngleLeftLabel, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_GetAngleLeftLabel, 0);
    lv_obj_set_x(ui_GetAngleLeftLabel, lv_pct(0));

    lv_obj_set_align(ui_GetAngleLeftLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_GetAngleLeftLabel, "Get Angle");

    lv_obj_set_style_text_font(ui_GetAngleLeftLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_GetAngleRightButton

    ui_GetAngleRightButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_GetAngleRightButton, 120);
    lv_obj_set_height(ui_GetAngleRightButton, 60);

    lv_obj_set_x(ui_GetAngleRightButton, lv_pct(24));
    lv_obj_set_y(ui_GetAngleRightButton, lv_pct(-36));

    lv_obj_set_align(ui_GetAngleRightButton, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_GetAngleRightButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_GetAngleRightButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_GetAngleRightButton, ui_event_GetAngleRightButton, LV_EVENT_ALL, NULL);

    // ui_GetAngleRgihtLabel

    ui_GetAngleRgihtLabel = lv_label_create(ui_GetAngleRightButton);

    lv_obj_set_width(ui_GetAngleRgihtLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_GetAngleRgihtLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_GetAngleRgihtLabel, 0);
    lv_obj_set_y(ui_GetAngleRgihtLabel, 0);

    lv_obj_set_align(ui_GetAngleRgihtLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_GetAngleRgihtLabel, "Get Angle");

    lv_obj_set_style_text_font(ui_GetAngleRgihtLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ProgramButton

    ui_ProgramButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_ProgramButton, 210);
    lv_obj_set_height(ui_ProgramButton, 90);

    lv_obj_set_x(ui_ProgramButton, lv_pct(-13));
    lv_obj_set_y(ui_ProgramButton, lv_pct(14));

    lv_obj_set_align(ui_ProgramButton, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ProgramButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ProgramButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ProgramButton, ui_event_ProgramButton, LV_EVENT_ALL, NULL);

    // ui_ProgramButtonLabel

    ui_ProgramButtonLabel = lv_label_create(ui_ProgramButton);

    lv_obj_set_width(ui_ProgramButtonLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ProgramButtonLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ProgramButtonLabel, 0);
    lv_obj_set_y(ui_ProgramButtonLabel, -1);

    lv_obj_set_align(ui_ProgramButtonLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ProgramButtonLabel, "Program");

    lv_obj_set_style_text_font(ui_ProgramButtonLabel, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PWMArc

    ui_PWMArc = lv_arc_create(ui_MainScreen);

    lv_obj_set_width(ui_PWMArc, 175);
    lv_obj_set_height(ui_PWMArc, 175);

    lv_obj_set_x(ui_PWMArc, lv_pct(-21));
    lv_obj_set_y(ui_PWMArc, lv_pct(37));

    lv_obj_set_align(ui_PWMArc, LV_ALIGN_CENTER);

    lv_arc_set_range(ui_PWMArc, -100, 100);
    lv_arc_set_bg_angles(ui_PWMArc, 120, 60);

    lv_obj_add_event_cb(ui_PWMArc, ui_event_PWMArc, LV_EVENT_ALL, NULL);

    lv_obj_set_style_arc_width(ui_PWMArc, 18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_width(ui_PWMArc, 18, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_PWMLabel

    ui_PWMLabel = lv_label_create(ui_PWMArc);

    lv_obj_set_width(ui_PWMLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_PWMLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_PWMLabel, 0);
    lv_obj_set_y(ui_PWMLabel, 0);

    lv_obj_set_align(ui_PWMLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_PWMLabel, "-100%");

    lv_obj_set_style_text_font(ui_PWMLabel, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SwipeTestButton

    ui_SwipeTestButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_SwipeTestButton, 110);
    lv_obj_set_height(ui_SwipeTestButton, 55);

    lv_obj_set_x(ui_SwipeTestButton, lv_pct(22));
    lv_obj_set_y(ui_SwipeTestButton, lv_pct(42));

    lv_obj_set_align(ui_SwipeTestButton, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_SwipeTestButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SwipeTestButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_SwipeTestButton, ui_event_SwipeTestButton, LV_EVENT_ALL, NULL);
    lv_obj_set_style_text_font(ui_SwipeTestButton, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SwipeTestLabel

    ui_SwipeTestLabel = lv_label_create(ui_SwipeTestButton);

    lv_obj_set_width(ui_SwipeTestLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SwipeTestLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_SwipeTestLabel, 0);
    lv_obj_set_y(ui_SwipeTestLabel, 0);

    lv_obj_set_align(ui_SwipeTestLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_SwipeTestLabel, "Swipe");

    // ui_Panel1

    ui_Panel1 = lv_obj_create(ui_MainScreen);

    lv_obj_set_height(ui_Panel1, 10);
    lv_obj_set_width(ui_Panel1, lv_pct(100));

    lv_obj_set_x(ui_Panel1, 0);
    lv_obj_set_y(ui_Panel1, lv_pct(22));

    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ReadConfigurationButton

    ui_ReadConfigurationButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_ReadConfigurationButton, 110);
    lv_obj_set_height(ui_ReadConfigurationButton, 55);

    lv_obj_set_x(ui_ReadConfigurationButton, lv_pct(28));
    lv_obj_set_y(ui_ReadConfigurationButton, lv_pct(14));

    lv_obj_set_align(ui_ReadConfigurationButton, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ReadConfigurationButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ReadConfigurationButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ReadConfigurationButton, ui_event_ReadConfigurationButton, LV_EVENT_ALL, NULL);
    lv_obj_set_style_text_font(ui_ReadConfigurationButton, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ReadConfigurationLabel

    ui_ReadConfigurationLabel = lv_label_create(ui_ReadConfigurationButton);

    lv_obj_set_width(ui_ReadConfigurationLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ReadConfigurationLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ReadConfigurationLabel, 0);
    lv_obj_set_y(ui_ReadConfigurationLabel, 0);

    lv_obj_set_align(ui_ReadConfigurationLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ReadConfigurationLabel, "Read");

    // ui_PWMControlButton

    ui_PWMControlButton = lv_btn_create(ui_MainScreen);

    lv_obj_set_width(ui_PWMControlButton, 110);
    lv_obj_set_height(ui_PWMControlButton, 55);

    lv_obj_set_x(ui_PWMControlButton, lv_pct(22));
    lv_obj_set_y(ui_PWMControlButton, lv_pct(32));

    lv_obj_set_align(ui_PWMControlButton, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_PWMControlButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PWMControlButton, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_PWMControlButton, ui_event_PWMControlButton, LV_EVENT_ALL, NULL);
    lv_obj_set_style_text_font(ui_PWMControlButton, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PWMControlLabel

    ui_PWMControlLabel = lv_label_create(ui_PWMControlButton);

    lv_obj_set_width(ui_PWMControlLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_PWMControlLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_PWMControlLabel, 0);
    lv_obj_set_y(ui_PWMControlLabel, 0);

    lv_obj_set_align(ui_PWMControlLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_PWMControlLabel, "Start");

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_MainScreen_screen_init();
    lv_disp_load_scr(ui_MainScreen);
}

