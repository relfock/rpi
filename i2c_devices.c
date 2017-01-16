#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/i2c-dev.h>

int i2c_fd;

void open_i2c_devices()
{
	i2c_fd = open("/dev/i2c-1", O_RDWR);
	if(i2c_fd < 0) {
		perror("i2c_open");
		exit(1);
	}
}

int read_temperature()
{
	uint8_t data[2] = { 0 };

	if(ioctl(i2c_fd, I2C_SLAVE, 0x48) < 0) {
		perror("ioctl");
		exit(1);
	}

	if(read(i2c_fd, data, 2) != 2) {
		perror("read");
	}

    temp = ((data[1] >> 7) | ((data[0] & 0x7F) << 1)) / 2;
    if(data[0] & 0x80)
        temp = -temp;

    return temp;
}

void close_i2c_devices()
{
	close(i2c_fd);
}
