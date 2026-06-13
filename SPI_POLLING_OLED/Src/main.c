#include <stdint.h>
#include "SPI.h"
#include "Display.h"
#include "OLED.h"


int main(void)
{
    SPI1_GPIO_INIT();
    SPI_Master_INIT();
    Display_Init();

    int anim_width = 64;
    int anim_height = 64;
    int start_x = 32;
    int start_y = 0;

    while(1)
    {
        // Loop using the variable calculated in Image.c
        for (int current_frame = 0; current_frame < ANIMATION_FRAMES_COUNT; current_frame++)
        {

            draw_bitmap(start_x, start_y, anim_width, anim_height, frames[current_frame]);

            Display_Update();

            delay(1);
        }
    }
}
