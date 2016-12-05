

moon: main.c motor.c tcp_server.c
	cc -o $@ $^ -lwiringPi

.PHONY: clean

clean:
	@rm -rf *.o moon
