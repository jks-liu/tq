#include "tq2440-lcd.h"
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdbool.h>

static int lcd;
static char *buffer;
static struct fb_var_screeninfo infomation;

#include <stdio.h>
bool tq2440_lcd_init(void) {
    lcd = open("/dev/fb/0", O_RDWR);
    if (lcd < 0) {
        printf("x0\n");
        return false;
    }

    if (ioctl(lcd, FBIOGET_VSCREENINFO, &infomation) < 0) {
        printf("x1\n");
        return false;
    }

    
    printf("fb memory info=xres (%d) x yres (%d), %d bpp\n",
           infomation.xres, infomation.yres, infomation.bits_per_pixel);

    buffer = mmap(0, infomation.xres * infomation.yres * (infomation.bits_per_pixel >> 3), PROT_READ | PROT_WRITE, MAP_SHARED, lcd, 0);
        
    return true;
}

void tq2440_lcd_set_color(int y, int x, uint32_t color) {
    char *buf = buffer + (y * infomation.xres + x) * (infomation.bits_per_pixel >> 3);
    //    printf("x%d, y%d, %ld\n", infomation.xres, infomation.yres, (long)infomation.bits_per_pixel);
    for (int i = 0; i < (infomation.bits_per_pixel >> 3); ++i) {
        *buf++ = color % 0x100;
        color /= 0x100;
    }
}


    




