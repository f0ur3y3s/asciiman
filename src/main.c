#include "../include/main.h"

// This is where the main game should go however it is being used to test the
// player animations

static _Atomic bool gb_run = true;
static void         sighandler (int signum);

static void sighandler (int signum)
{
    if (SIGINT == signum)
    {
        gb_run = false;
    }
}

static void install_sighandler (void)
{
    struct sigaction sigaction_handler = { .sa_handler = sighandler };
    sigaction(SIGINT, &sigaction_handler, NULL);
}

int main (void)
{
    install_sighandler();

    int        width    = 100;
    int        height   = 10;
    screen_t * p_screen = screen_init(width, height);
    screen_clear(p_screen);
    player_init();

    int total_offset = 0;

    char idle[3]   = { LLEG_IDLE, ' ', RLEG_IDLE };
    char rwalk1[3] = { ' ', RWALK_BENT, RLEG_IDLE };
    char rwalk2[3] = { ' ', LEG_CENTER, RLEG_IDLE };
    char rwalk3[3] = { ' ', LEG_CENTER, RWALK_BENT };

    player_walk_anim_t rwalk_anim[4] = {
        { idle, (point_t) { .x = 1, .y = 0 } },
        { rwalk1, (point_t) { .x = 0, .y = 0 } },
        { rwalk2, (point_t) { .x = 1, .y = 0 } },
        { rwalk3, (point_t) { .x = 0, .y = 0 } },
    };

    // player_walk_anim_t lwalk_anim[4] = {
    //     { idle, (point_t) { .x = 1, .y = 0 } },
    //     { lwalk1, (point_t) { .x = 0, .y = 0 } },
    //     { lwalk2, (point_t) { .x = 1, .y = 0 } },
    //     { lwalk3, (point_t) { .x = 0, .y = 0 } },
    // };

    while (gb_run)
    {
        for (int i = 0; i < 4; i++)
        {
            total_offset += rwalk_anim[i].offset.x;

            for (int x = 0; x < 3; x++)
            {
                screen_modify(p_screen,
                              (point_t) { .x = total_offset + x, .y = 0 },
                              rwalk_anim[i].p_arr[(0 * 3) + x]);
            }

            screen_display(p_screen);
            usleep(200000);
            screen_clear(p_screen);
        }

        if (total_offset > width/2)
        {
            total_offset = 0;
        }
    }

    screen_destroy(&p_screen);
    return 0;
}