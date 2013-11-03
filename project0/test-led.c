#include "tq2440-led.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    tq2440_led_init();
    for(;;) {
        for (int i = 1; i <= 4; ++i) {
            tq2440_led_on(i);
            sleep(1);
            tq2440_led_off(i);
            sleep(1);
        }
    }
    return 0;
}
        

