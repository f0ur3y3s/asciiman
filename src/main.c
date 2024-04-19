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

typedef enum movement_keys_t
{
    MOVEMENT_KEY_UP    = 119,
    MOVEMENT_KEY_DOWN  = 115,
    MOVEMENT_KEY_RIGHT = 100,
    MOVEMENT_KEY_LEFT  = 97
} movement_keys_t;

int main (void)
{
    install_sighandler();

    int        width    = 100;
    int        height   = 10;
    screen_init(width, height);
    screen_clear();
    player_init();
    player_walk_right();

    while (gb_run)
    {
        char    chr[3]      = { 0 };
        ssize_t bytes_read  = 0;
        bytes_read          = read(STDIN_FILENO, &chr, 3);
        player_t * p_player = player_get();

        if (0 > bytes_read)
        {
            player_idle();
            // continue;
        }
        else
        {
            if (3 == chr[0])
            {
                fprintf(stdout, "Exiting...\n");
                break;
            }

            switch (chr[0])
            {
                case MOVEMENT_KEY_UP:
                    if (p_player->dir != DIR_IDLE)
                        player_idle();
                    break;
                case MOVEMENT_KEY_DOWN:
                    if (p_player->dir != DIR_IDLE)
                        player_idle();
                    break;
                case MOVEMENT_KEY_RIGHT:
                    if (p_player->dir != DIR_RIGHT)
                    {
                        player_walk_right();
                    }
                    break;
                case MOVEMENT_KEY_LEFT:
                    if (p_player->dir != DIR_LEFT)
                    {

                        player_walk_left();
                    }
                    break;
                default:
                    if (p_player->dir != DIR_IDLE)
                        player_idle();
                    continue;
            }
        }

        player_step();
        screen_clear();

        p_player            = player_get();
        char * p_player_arr = player_export();

        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                screen_modify(
                    (point_t) { .x = x + p_player->pos.x, .y = y + height - 3 },
                    p_player_arr[(y * 3) + x]);
            }
        }

        screen_display();

        usleep(80000);
    }

    player_destroy();
    screen_destroy();
    return 0;
}