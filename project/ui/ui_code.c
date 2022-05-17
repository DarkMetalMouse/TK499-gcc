#include "ui_code.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdbool.h>

// static int label_angle = 0;
static bool connected = false;

void ui_set_angle(int angle)
{

    // if (angle > lv_arc_get_max_value(ui_AngleArc) || angle < lv_arc_get_min_value(ui_AngleArc))
    //     return;
    // if (label_angle != angle)
    // {
    //     char buf[_UI_TEMPORARY_STRING_BUFFER_SIZE];

    //     lv_snprintf(buf, sizeof(buf), "%d", angle);
    //     // send_str(buf);
    //     lv_label_set_text(ui_AngleLabel, buf);
    //     lv_arc_set_value(ui_AngleArc, angle);
    //     label_angle = angle;
    // }
}

void ui_set_connection(bool connect)
{
    if (connect != connected)
    {
        if (connect)
        {
            lv_label_set_text(ui_ConnectionLabel, "#10E027 CONNECTED#");
        }
        else
        {
            lv_label_set_text(ui_ConnectionLabel, "#DF1717 DISCONNECTED#");
        }
        connected = connect;
    }
}
