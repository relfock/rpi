
enum dir {
    LEFT,
    RIGHT
};

void tcp_server(void);
int motor_init(int pin);
int control_motor(int pin, enum dir direction);
