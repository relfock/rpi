#include <unistd.h>

#include "rpi.h"

// We're using the Broadcom chip pin numbers.
// PWM motor - Broadcom pin 18, P1 pin 12
int motor_pin = 18;

int main()
{
#if 0
    daemon(0, 0);
#endif

    motor_init(motor_pin);
    tcp_server();

    return 0;
}
