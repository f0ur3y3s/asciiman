#include "../include/main.h"

int main (void)
{
    screen_t * p_screen = screen_init(20, 10);

    // player_print();
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            screen_modify(p_screen, (point_t){.x = x  , .y = y}, 'c');
            screen_update(p_screen);
            usleep(50000);
        }
    }

    sleep(1);
    // screen_modify(p_screen, (point_t){.x = 0, .y = 0}, 'c');
    // screen_update(p_screen);
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