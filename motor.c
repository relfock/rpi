#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

#include "rpi.h"

int motor_init(int pin)
{
    char * str;
    wiringPiSetupGpio();
    pinMode(pin, OUTPUT);

    return 0;
}

int control_motor(int pin, enum dir direction)
{
    int pw;

    switch(direction) {
        case LEFT:
            pw = 2500;
            printf("Turn motor LEFT\n");
            break;
        case RIGHT:
            printf("Turn motor RIGHT\n");
            pw = 500;
            break;
        default:
            // rotate to center
            printf("Turn motor CENTER\n");
            pw = 1500;
            break;
    }

    digitalWrite(pin, 1);
    usleep(pw);
    digitalWrite(pin, 0);

    return 0;
}
