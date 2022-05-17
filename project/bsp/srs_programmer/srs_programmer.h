#ifndef _SRS_PROGRAMMER_H
#define _SRS_PROGRAMMER_H

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
srs_programming_state_t get_programming_status();

#endif