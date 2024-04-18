#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "unity/unity.h"

#include "../include/screen.h"

void setUp (void)
{
}

void tearDown (void)
{
}

int main (void)
{
    UNITY_BEGIN();
    return UNITY_END();
}

// testing animations

// for (int x = 0; x < width; x++)
// {
//     screen_modify(p_screen, (point_t) { .x = x, .y = 0 }, 'c');
//     usleep(5000);
// }

// screen_display(p_screen);

// for (int row = 0; row < height; row++)
// {
//     screen_shift_h(p_screen, row, row + 1);
//     usleep(5000);
// }

// for (int y = 0; y < height; y++)
// {
//     screen_modify(p_screen, (point_t) { .x = 0, .y = y }, 'c');
//     usleep(5000);
// }
// screen_display(p_screen);

// for (int col = 0; col < width; col++)
// {
//     screen_shift_v(p_screen, col, col + 1);
//     usleep(5000);
// }