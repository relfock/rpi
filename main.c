#include <unistd.h>
#include <stdio.h>

#include "rpi.h"
#include "i2c_devices.h"

// We're using the Broadcom chip pin numbers.
// PWM motor - Broadcom pin 18, P1 pin 12
int motor_pin = 18;

int main()
{
#if 0
    daemon(0, 0);
#endif

    printf("Initializing Motor ...\n");
    motor_init(motor_pin);
    open_i2c_devices();

    printf("Initializing TCP Server ...\n");
    tcp_server();

    close_i2c_devices();

    return 0;
}
