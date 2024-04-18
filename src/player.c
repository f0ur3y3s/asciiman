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

char gp_player_arr[9] = { 0 };

// void player_step (void)
// {
//     // a player is formatted into a 3x3 grid
//     // printf("%d %d\n", g_player.dir, g_player.dir_iter);
//     // printf("x,y: %d, %d\n\n", g_player.pos.x, g_player.pos.y);

//     // printf(HEAD_IDLE, g_player.head[0]);
//     // printf(BODY_IDLE, g_player.larm[0], g_player.body[0],
//     g_player.rarm[0]);

//     // row 3

//     // #define RWALK_FIRST  0b011
//     // #define RWALK_SECOND 0b101
//     // #define LWALK_FIRST  0b110
//     // #define LWALK_SECOND 0b101
//     switch (g_player.dir)
//     {
//         case DIR_LEFT:
//             // walking left
//             if (0 == g_player.dir_iter % 2)
//             {
//                 printf(LWALK_FIRST, g_player.lleg[0], g_player.rleg[0]);
//             }
//             else
//             {
//                 printf(LWALK_SECOND, g_player.lleg[0], g_player.rleg[0]);
//             }

//             g_player.dir_iter = (g_player.dir_iter + 1) % 2;
//             player_walk_left();

//             break;
//         case DIR_RIGHT:
//             // walking right
//             if (0 == g_player.dir_iter % 2)
//             {
//                 printf(RWALK_FIRST, g_player.lleg[0], g_player.rleg[0]);
//             }
//             else
//             {
//                 printf(RWALK_SECOND, g_player.lleg[0], g_player.rleg[0]);
//             }

//             g_player.dir_iter = (g_player.dir_iter + 1) % 2;
//             player_walk_right();

//             break;
//         default:
//             printf("%c %c\n", g_player.lleg[0], g_player.rleg[0]);
//             break;
//     }
// }

void player_init (void)
{
    gp_player_arr[0] = 0;
    gp_player_arr[1] = g_player.head[0];
    gp_player_arr[2] = 0;
    gp_player_arr[3] = g_player.larm[0];
    gp_player_arr[4] = g_player.body[0];
    gp_player_arr[5] = g_player.rarm[0];
    gp_player_arr[6] = g_player.lleg[0];
    gp_player_arr[7] = 0;
    gp_player_arr[8] = g_player.rleg[0];
}

void player_walk_right (void)
{
    if (DIR_RIGHT == g_player.dir)
    {
        g_player.pos.x++;
    }

    // if player dir is already right, switch legs
    if (0 == g_player.dir_iter % 2)
    {
        g_player.lleg[0] = LLEG_RWALK_FIRST;
        g_player.rleg[0] = RLEG_RWALK_FIRST;
        gp_player_arr[6] = 0;
        gp_player_arr[7] = g_player.lleg[0];
        gp_player_arr[8] = g_player.rleg[0];
    }
    else
    {
        g_player.lleg[0] = LLEG_RWALK_SECOND;
        g_player.rleg[0] = RLEG_RWALK_SECOND;
        gp_player_arr[6] = g_player.lleg[0];
        gp_player_arr[7] = 0;
        gp_player_arr[8] = g_player.rleg[0];
    }

    g_player.dir_iter = (g_player.dir_iter + 1) % 2;
    g_player.dir      = DIR_RIGHT;
}

void player_walk_left (void)
{
    if (DIR_LEFT == g_player.dir)
    {
        g_player.pos.x--;
    }

    if (0 == g_player.dir_iter % 2)
    {
        g_player.lleg[0] = LLEG_LWALK_FIRST;
        g_player.rleg[0] = RLEG_LWALK_FIRST;
        gp_player_arr[6] = g_player.lleg[0];
        gp_player_arr[7] = g_player.rleg[0];
        gp_player_arr[8] = 0;
    }
    else
    {
        g_player.lleg[0] = LLEG_LWALK_SECOND;
        g_player.rleg[0] = RLEG_LWALK_SECOND;
        gp_player_arr[6] = g_player.lleg[0];
        gp_player_arr[7] = 0;
        gp_player_arr[8] = g_player.rleg[0];
    }

    g_player.dir_iter = (g_player.dir_iter + 1) % 2;
    g_player.dir      = DIR_LEFT;
}

void player_idle (void)
{
    g_player.lleg[0]  = LLEG_IDLE;
    g_player.rleg[0]  = RLEG_IDLE;
    g_player.dir      = 0;
    g_player.dir_iter = 0;
    gp_player_arr[6]  = g_player.lleg[0];
    gp_player_arr[7]  = 0;
    gp_player_arr[8]  = g_player.rleg[0];
}

char * player_export (void)
{
    return (gp_player_arr);
}

player_t * player_get (void)
{
    return (&g_player);
}