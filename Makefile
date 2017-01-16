
all: moon client

moon: main.c motor.c tcp_server.c i2c_devices.c
	cc -o $@ $^ -lwiringPi

client: tcp_client.c
	cc -o $@ $^

.PHONY: clean all

clean:
	@rm -rf *.o moon
