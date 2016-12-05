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
            break;
        case RIGHT:
            pw = 500;
            break;
        default:
            // rotate to center
            pw = 1500;
            break;
    }
    digitalWrite(pin, 1);
    usleep(pw);
    digitalWrite(pin, 0);
}
