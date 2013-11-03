#include "tq2440-led.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

static int led;

bool tq2440_led_init(void) {
    led = open("/dev/GPIO-Control", 0);
    return led == 0;
}

int tq2440_led_on(int index) {
    return ioctl(led, 1, index - 1);
}

int tq2440_led_off(int index) {
    return ioctl(led, 0, index - 1);
}

