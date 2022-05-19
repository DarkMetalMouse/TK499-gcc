#ifndef _SRS_PROGRAMMER_H
#define _SRS_PROGRAMMER_H

#define map(x, x1, y1, x2, y2) ((x) - (x2)) * ((y2) - (y1)) / ((x2) - (x1)) + (y2)

typedef enum srs_programming_state
{
    PROGRAMMING,
    NOT_PROGRAMMING,
    PROGRAMMING_SUCCESS,
    PROGRAMMING_FAIL
} srs_programming_state_t;

int get_angle();
void srs_programmer_init();
void program_continuos();
void program_servo_angles(int left_angle, int right_angle);
void set_pwm_output(int duty_us);
srs_programming_state_t get_programming_status();

#endif