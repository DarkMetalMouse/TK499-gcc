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
lv_obj_t * ui_AngleArc;
lv_obj_t * ui_AngleLabel;

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
void ui_MainScreen_screen_init(void)
{

    // ui_MainScreen

    ui_MainScreen = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);

    // ui_HeaderPanel

    ui_HeaderPanel = lv_obj_create(ui_MainScreen);

    lv_obj_set_height(ui_HeaderPanel, 50);
    lv_obj_set_width(ui_HeaderPanel, lv_pct(100));

    lv_obj_set_x(ui_HeaderPanel, 0);
    lv_obj_set_y(ui_HeaderPanel, 0);

    lv_obj_set_align(ui_HeaderPanel, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_HeaderPanel, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_HeaderPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ConnectionLabel

    ui_ConnectionLabel = lv_label_create(ui_HeaderPanel);

    lv_obj_set_width(ui_ConnectionLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ConnectionLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ConnectionLabel, 0);
    lv_obj_set_y(ui_ConnectionLabel, 0);

    lv_obj_set_align(ui_ConnectionLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_ConnectionLabel, "DISCONNECTED");
    lv_label_set_recolor(ui_ConnectionLabel, "true");

    lv_obj_set_style_text_color(ui_ConnectionLabel, lv_color_hex(0xDF1717), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ConnectionLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ConnectionLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_AngleArc

    ui_AngleArc = lv_arc_create(ui_MainScreen);

    lv_obj_set_width(ui_AngleArc, 150);
    lv_obj_set_height(ui_AngleArc, 150);

    lv_obj_set_x(ui_AngleArc, 2);
    lv_obj_set_y(ui_AngleArc, 0);

    lv_obj_set_align(ui_AngleArc, LV_ALIGN_CENTER);

    lv_obj_add_state(ui_AngleArc, LV_STATE_DISABLED);

    lv_arc_set_range(ui_AngleArc, -179, 180);
    lv_arc_set_bg_angles(ui_AngleArc, 0, 360);

    lv_obj_set_style_arc_color(ui_AngleArc, lv_color_hex(0x2F3237), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_AngleArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_AngleArc, lv_color_hex(0x2F3237), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_AngleArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // ui_AngleLabel

    ui_AngleLabel = lv_label_create(ui_AngleArc);

    lv_obj_set_width(ui_AngleLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_AngleLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_AngleLabel, 0);
    lv_obj_set_y(ui_AngleLabel, 0);

    lv_obj_set_align(ui_AngleLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_AngleLabel, "0");

    lv_obj_set_style_text_font(ui_AngleLabel, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

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

