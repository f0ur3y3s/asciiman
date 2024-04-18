#include "../include/player.h"

player_t g_player = { .head     = { HEAD },
                      .body     = { BODY },
                      .larm     = { LARM_IDLE },
                      .rarm     = { RARM_IDLE },
                      .lleg     = { LLEG_IDLE },
                      .rleg     = { RLEG_IDLE },
                      .dir      = DIR_IDLE,
                      .dir_iter = 0,
                      .pos      = { .x = 0, .y = 0 } };

void player_print (void)
{
    // a player is formatted into a 3x3 grid

    printf(HEAD_IDLE, g_player.head[0]);
    printf(BODY_IDLE, g_player.larm[0], g_player.body[0], g_player.rarm[0]);

    // row 3
    switch (g_player.dir)
    {
        case DIR_LEFT:
            // walking left
            if (0 == g_player.dir_iter % 2)
            {
                printf(LWALK_FIRST, g_player.lleg[0], g_player.rleg[0]);
            }
            else
            {
                printf(LWALK_SECOND, g_player.lleg[0], g_player.rleg[0]);
            }

            g_player.dir_iter = (g_player.dir_iter + 1) % 2;
            player_walk_left();

            break;
        case DIR_RIGHT:
            // walking right
            if (0 == g_player.dir_iter % 2)
            {
                printf(RWALK_FIRST, g_player.lleg[0], g_player.rleg[0]);
            }
            else
            {
                printf(RWALK_SECOND, g_player.lleg[0], g_player.rleg[0]);
            }

            g_player.dir_iter = (g_player.dir_iter + 1) % 2;
            player_walk_right();

            break;
        default:
            printf("%c %c\n", g_player.lleg[0], g_player.rleg[0]);
            break;
    }
}

void player_walk_right (void)
{
    // if player dir is already right, switch legs
    if (0 == g_player.dir_iter % 2)
    {
        g_player.lleg[0] = LLEG_RWALK_FIRST;
        g_player.rleg[0] = RLEG_RWALK_FIRST;
    }
    else
    {
        g_player.lleg[0] = LLEG_RWALK_SECOND;
        g_player.rleg[0] = RLEG_RWALK_SECOND;
    }

    g_player.dir = DIR_LEFT;
}

void player_walk_left (void)
{
    if (0 == g_player.dir_iter % 2)
    {
        g_player.lleg[0] = LLEG_LWALK_FIRST;
        g_player.rleg[0] = RLEG_LWALK_FIRST;
    }
    else
    {
        g_player.lleg[0] = LLEG_LWALK_SECOND;
        g_player.rleg[0] = RLEG_LWALK_SECOND;
    }

    g_player.dir = DIR_RIGHT;
}

void player_idle (void)
{
    g_player.lleg[0]  = LLEG_IDLE;
    g_player.rleg[0]  = RLEG_IDLE;
    g_player.dir      = 0;
    g_player.dir_iter = 0;
}