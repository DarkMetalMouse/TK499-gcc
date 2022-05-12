// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Arc1;
lv_obj_t * ui_Label1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void ui_event_Arc1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_Label1, ta, "", "");
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{

    // ui_Screen1

    ui_Screen1 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Arc1

    ui_Arc1 = lv_arc_create(ui_Screen1);

    lv_obj_set_width(ui_Arc1, 250);
    lv_obj_set_height(ui_Arc1, 250);

    lv_obj_set_x(ui_Arc1, 0);
    lv_obj_set_y(ui_Arc1, 0);

    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);

    lv_arc_set_range(ui_Arc1, -135, 135);
    lv_arc_set_bg_angles(ui_Arc1, 135, 45);
    lv_arc_set_mode(ui_Arc1, LV_ARC_MODE_SYMMETRICAL);

    lv_obj_add_event_cb(ui_Arc1, ui_event_Arc1, LV_EVENT_ALL, NULL);

    lv_obj_set_style_border_color(ui_Arc1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Arc1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_width(ui_Arc1, 18, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Arc1, 2, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Label1

    ui_Label1 = lv_label_create(ui_Arc1);

    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label1, 0);
    lv_obj_set_y(ui_Label1, 0);

    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label1, "0");

    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}

