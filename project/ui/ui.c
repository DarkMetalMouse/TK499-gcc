// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Bar1;
lv_obj_t * ui_Slider1;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Bar2;
lv_obj_t * ui_Slider2;
lv_obj_t * ui_Panel3;
lv_obj_t * ui_Bar3;
lv_obj_t * ui_Slider3;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_Bar4;
lv_obj_t * ui_Slider4;
lv_obj_t * ui_Panel5;
lv_obj_t * ui_Bar5;
lv_obj_t * ui_Slider5;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{

    // ui_Screen1

    ui_Screen1 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Panel1

    ui_Panel1 = lv_obj_create(ui_Screen1);

    lv_obj_set_height(ui_Panel1, 145);
    lv_obj_set_width(ui_Panel1, lv_pct(100));

    lv_obj_set_x(ui_Panel1, 0);
    lv_obj_set_y(ui_Panel1, lv_pct(-40));

    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Bar1

    ui_Bar1 = lv_bar_create(ui_Panel1);
    lv_bar_set_range(ui_Bar1, 0, 29);
    lv_bar_set_value(ui_Bar1, 29, LV_ANIM_OFF);

    lv_obj_set_width(ui_Bar1, 350);
    lv_obj_set_height(ui_Bar1, 30);

    lv_obj_set_y(ui_Bar1, 47);
    lv_obj_set_x(ui_Bar1, lv_pct(0));

    lv_obj_set_align(ui_Bar1, LV_ALIGN_CENTER);

    lv_obj_set_style_radius(ui_Bar1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Bar1, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Bar1, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Bar1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Bar1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bar1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Bar1, &ui_img_indicator_ver_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Slider1

    ui_Slider1 = lv_slider_create(ui_Panel1);
    lv_slider_set_range(ui_Slider1, 0, 1023);
    lv_slider_set_value(ui_Slider1, 1023, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider1) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider1, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_Slider1, 348);
    lv_obj_set_height(ui_Slider1, 50);

    lv_obj_set_y(ui_Slider1, -20);
    lv_obj_set_x(ui_Slider1, lv_pct(0));

    lv_obj_set_align(ui_Slider1, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0x525252), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider1, &ui_img_pot_hor_line_tempo_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider1, 22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider1, 22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0x50FF7D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider1, 12, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider1, &ui_img_pot_hor_knob_png, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider1, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider1, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider1, 35, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider1, 35, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Panel2

    ui_Panel2 = lv_obj_create(ui_Screen1);

    lv_obj_set_height(ui_Panel2, 145);
    lv_obj_set_width(ui_Panel2, lv_pct(100));

    lv_obj_set_x(ui_Panel2, 0);
    lv_obj_set_y(ui_Panel2, lv_pct(-20));

    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Bar2

    ui_Bar2 = lv_bar_create(ui_Panel2);
    lv_bar_set_range(ui_Bar2, 0, 29);
    lv_bar_set_value(ui_Bar2, 29, LV_ANIM_OFF);

    lv_obj_set_width(ui_Bar2, 350);
    lv_obj_set_height(ui_Bar2, 30);

    lv_obj_set_y(ui_Bar2, 47);
    lv_obj_set_x(ui_Bar2, lv_pct(0));

    lv_obj_set_align(ui_Bar2, LV_ALIGN_CENTER);

    lv_obj_set_style_radius(ui_Bar2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Bar2, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Bar2, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Bar2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Bar2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bar2, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar2, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar2, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Bar2, &ui_img_indicator_ver_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Slider2

    ui_Slider2 = lv_slider_create(ui_Panel2);
    lv_slider_set_range(ui_Slider2, 0, 1023);
    lv_slider_set_value(ui_Slider2, 1023, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider2) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider2, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_Slider2, 348);
    lv_obj_set_height(ui_Slider2, 50);

    lv_obj_set_y(ui_Slider2, -20);
    lv_obj_set_x(ui_Slider2, lv_pct(0));

    lv_obj_set_align(ui_Slider2, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0x525252), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider2, &ui_img_pot_hor_line_tempo_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider2, 22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider2, 22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0x50FF7D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider2, 12, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider2, &ui_img_pot_hor_knob_png, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider2, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider2, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider2, 35, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider2, 35, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Panel3

    ui_Panel3 = lv_obj_create(ui_Screen1);

    lv_obj_set_height(ui_Panel3, 145);
    lv_obj_set_width(ui_Panel3, lv_pct(100));

    lv_obj_set_x(ui_Panel3, 0);
    lv_obj_set_y(ui_Panel3, lv_pct(0));

    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Bar3

    ui_Bar3 = lv_bar_create(ui_Panel3);
    lv_bar_set_range(ui_Bar3, 0, 29);
    lv_bar_set_value(ui_Bar3, 29, LV_ANIM_OFF);

    lv_obj_set_width(ui_Bar3, 350);
    lv_obj_set_height(ui_Bar3, 30);

    lv_obj_set_y(ui_Bar3, 47);
    lv_obj_set_x(ui_Bar3, lv_pct(0));

    lv_obj_set_align(ui_Bar3, LV_ALIGN_CENTER);

    lv_obj_set_style_radius(ui_Bar3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Bar3, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Bar3, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Bar3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Bar3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bar3, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar3, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar3, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Bar3, &ui_img_indicator_ver_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Slider3

    ui_Slider3 = lv_slider_create(ui_Panel3);
    lv_slider_set_range(ui_Slider3, 0, 1023);
    lv_slider_set_value(ui_Slider3, 1023, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider3) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider3, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_Slider3, 348);
    lv_obj_set_height(ui_Slider3, 50);

    lv_obj_set_y(ui_Slider3, -20);
    lv_obj_set_x(ui_Slider3, lv_pct(0));

    lv_obj_set_align(ui_Slider3, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Slider3, lv_color_hex(0x525252), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider3, &ui_img_pot_hor_line_tempo_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider3, 22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider3, 22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider3, lv_color_hex(0x50FF7D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider3, 12, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider3, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider3, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider3, &ui_img_pot_hor_knob_png, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider3, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider3, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider3, 35, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider3, 35, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Panel4

    ui_Panel4 = lv_obj_create(ui_Screen1);

    lv_obj_set_height(ui_Panel4, 145);
    lv_obj_set_width(ui_Panel4, lv_pct(100));

    lv_obj_set_x(ui_Panel4, 0);
    lv_obj_set_y(ui_Panel4, lv_pct(20));

    lv_obj_set_align(ui_Panel4, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Bar4

    ui_Bar4 = lv_bar_create(ui_Panel4);
    lv_bar_set_range(ui_Bar4, 0, 29);
    lv_bar_set_value(ui_Bar4, 29, LV_ANIM_OFF);

    lv_obj_set_width(ui_Bar4, 350);
    lv_obj_set_height(ui_Bar4, 30);

    lv_obj_set_y(ui_Bar4, 47);
    lv_obj_set_x(ui_Bar4, lv_pct(0));

    lv_obj_set_align(ui_Bar4, LV_ALIGN_CENTER);

    lv_obj_set_style_radius(ui_Bar4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Bar4, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Bar4, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Bar4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Bar4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bar4, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar4, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar4, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Bar4, &ui_img_indicator_ver_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Slider4

    ui_Slider4 = lv_slider_create(ui_Panel4);
    lv_slider_set_range(ui_Slider4, 0, 1023);
    lv_slider_set_value(ui_Slider4, 1023, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider4) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider4, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_Slider4, 348);
    lv_obj_set_height(ui_Slider4, 50);

    lv_obj_set_y(ui_Slider4, -20);
    lv_obj_set_x(ui_Slider4, lv_pct(0));

    lv_obj_set_align(ui_Slider4, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Slider4, lv_color_hex(0x525252), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider4, &ui_img_pot_hor_line_tempo_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider4, 22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider4, 22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider4, lv_color_hex(0x50FF7D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider4, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider4, 12, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider4, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider4, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider4, &ui_img_pot_hor_knob_png, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider4, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider4, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider4, 35, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider4, 35, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_Panel5

    ui_Panel5 = lv_obj_create(ui_Screen1);

    lv_obj_set_height(ui_Panel5, 145);
    lv_obj_set_width(ui_Panel5, lv_pct(100));

    lv_obj_set_x(ui_Panel5, 0);
    lv_obj_set_y(ui_Panel5, lv_pct(40));

    lv_obj_set_align(ui_Panel5, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel5, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Bar5

    ui_Bar5 = lv_bar_create(ui_Panel5);
    lv_bar_set_range(ui_Bar5, 0, 29);
    lv_bar_set_value(ui_Bar5, 29, LV_ANIM_OFF);

    lv_obj_set_width(ui_Bar5, 350);
    lv_obj_set_height(ui_Bar5, 30);

    lv_obj_set_y(ui_Bar5, 47);
    lv_obj_set_x(ui_Bar5, lv_pct(0));

    lv_obj_set_align(ui_Bar5, LV_ALIGN_CENTER);

    lv_obj_set_style_radius(ui_Bar5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Bar5, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Bar5, -1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Bar5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Bar5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Bar5, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Bar5, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bar5, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Bar5, &ui_img_indicator_ver_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_Slider5

    ui_Slider5 = lv_slider_create(ui_Panel5);
    lv_slider_set_range(ui_Slider5, 0, 1023);
    lv_slider_set_value(ui_Slider5, 1023, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider5) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider5, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_Slider5, 348);
    lv_obj_set_height(ui_Slider5, 50);

    lv_obj_set_y(ui_Slider5, -20);
    lv_obj_set_x(ui_Slider5, lv_pct(0));

    lv_obj_set_align(ui_Slider5, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_Slider5, lv_color_hex(0x525252), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider5, &ui_img_pot_hor_line_tempo_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider5, 22, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider5, 22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider5, lv_color_hex(0x50FF7D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider5, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_Slider5, 12, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Slider5, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider5, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Slider5, &ui_img_pot_hor_knob_png, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Slider5, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Slider5, -1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Slider5, 35, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Slider5, 35, LV_PART_KNOB | LV_STATE_DEFAULT);

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

