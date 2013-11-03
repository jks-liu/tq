#include "tq2440-lcd.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    tq2440_lcd_init();
#if 1
    for (int i = 0; i < 240; ++i) {
        for (int j = 0; j < 240; ++j) {
            tq2440_lcd_set_color(i, j, 255);
        }
    }
#endif
    return 0;
}

