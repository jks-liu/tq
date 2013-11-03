VPATH += ../tq2440-hardware-lib

CC = arm-none-linux-gnueabi-gcc

CFLAGS += -march=armv4t 
CFLAGS += -std=c99
CFLAGS += -Wall
CFLAGS += -Os
CFLAGS += -I../tq2440-hardware-lib

LDFLAGS += -march=armv4t

led_target = test-led
led_objects += $(led_target).o tq2440-led.o
$(led_target): $(led_objects)

targets += $(led_target)


.PHONY: all clean
all: $(targets)
clean:
	rm -rf *.o
	rm -rf $(targets)

