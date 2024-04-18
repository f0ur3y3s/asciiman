#include "../include/main.h"

int main (void)
{
    int        width    = 40;
    int        height   = 10;
    screen_t * p_screen = screen_init(width, height);


    // for (int y = 0; y < height; y++)
    // {
    //     for (int x = 0; x < width; x++)
    //     {
    //         if (y % 2 == 0)
    //         {
    //             screen_modify(p_screen, (point_t) { .x = x, .y = y }, 'c');
    //         }
    //         else
    //         {
    //             screen_modify(p_screen, (point_t) { .x = 19 - x, .y = y },
    //             'c');
    //         }
    //         screen_update(p_screen);
    //         usleep(5000);
    //     }
    // }
    for (int x = 0; x < width; x++)
    {
        screen_modify(p_screen, (point_t) { .x = x, .y = 0 }, 'c');
        screen_update(p_screen);
        usleep(5000);
    }

    for (int row = 0; row < height; row++)
    {
        screen_shift_h(p_screen, row, row + 1);
        usleep(50000);
    }

    for (int y = 0; y < height; y++)
    {
        screen_modify(p_screen, (point_t){.x = 0, .y = y}, 'c');
        screen_update(p_screen);
        usleep(5000);
    }

    // for (int col = 0; col < width; col++)
    // {
    //     screen_shift_v(p_screen, col, col + 1);
    //     usleep(5000);
    // }

    sleep(1);
    screen_destroy(&p_screen);
    // player_print();
    // sleep(1);
    // player_walk_right();
    // term_clear();
    // player_print();
    // sleep(1);
    // term_clear();
    // player_print();
    // sleep(1);
    // term_clear();
    // player_print();
    // sleep(1);
    // term_clear();
    // player_print();
    // sleep(1);
    // player_walk_left();
    // term_clear();
    // player_print();
    // sleep(1);
    // term_clear();
    // player_print();
    // sleep(1);
    // term_clear();
    // player_print();
    // sleep(1);
    // term_clear();
    // player_print();
    // sleep(1);
    // player_idle();
    // term_clear();
    // player_print();
    // sleep(1);
    return 0;
}