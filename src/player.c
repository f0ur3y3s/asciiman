#include "../include/player.h"

static player_t g_player = { .head        = { HEAD },
                      .body        = { BODY },
                      .larm        = { LARM_IDLE },
                      .rarm        = { RARM_IDLE },
                      .lleg        = { LLEG_IDLE },
                      .rleg        = { RLEG_IDLE },
                      .dir         = DIR_IDLE,
                      .pos         = { .x = 0, .y = 0 },
                      .pp_anim_arr = NULL };

static char gp_player_arr[9] = { 0 };

// Internal static stack character array
static char idle[3]   = { LLEG_IDLE, PLAYER_EMPTY, RLEG_IDLE };
static char rwalk1[3] = { PLAYER_EMPTY, RWALK_BENT, RLEG_IDLE };
static char rwalk2[3] = { PLAYER_EMPTY, LEG_CENTER, RLEG_IDLE };
static char rwalk3[3] = { PLAYER_EMPTY, LEG_CENTER, RWALK_BENT };
static char lwalk1[3] = { LLEG_IDLE, LWALK_BENT, PLAYER_EMPTY };
static char lwalk2[3] = { LLEG_IDLE, LEG_CENTER, PLAYER_EMPTY };
static char lwalk3[3] = { LWALK_BENT, LEG_CENTER, PLAYER_EMPTY };

// internal static structs for walk frames
static player_anim_frame_t pa_idle0[] = {
    idle,
    (point_t) { .x = 0, .y = 0 },
};
static player_anim_frame_t pa_rwalk0[] = {
    idle,
    (point_t) { .x = 1, .y = 0 },
};
static player_anim_frame_t pa_rwalk1[] = {
    rwalk1,
    (point_t) { .x = 0, .y = 0 },
};
static player_anim_frame_t pa_rwalk2[] = {
    rwalk2,
    (point_t) { .x = 1, .y = 0 },
};
static player_anim_frame_t pa_rwalk3[] = {
    rwalk3,
    (point_t) { .x = 0, .y = 0 },
};
static player_anim_frame_t pa_lwalk0[] = {
    idle,
    (point_t) { .x = -1, .y = 0 },
};
static player_anim_frame_t pa_lwalk1[] = {
    lwalk1,
    (point_t) { .x = 0, .y = 0 },
};
static player_anim_frame_t pa_lwalk2[] = {
    lwalk2,
    (point_t) { .x = -1, .y = 0 },
};
static player_anim_frame_t pa_lwalk3[] = {
    lwalk3,
    (point_t) { .x = 0, .y = 0 },
};

void player_init (void)
{
    g_player.pp_anim_arr = calloc(3, sizeof(csll_t *));

    g_player.pp_anim_arr[DIR_IDLE] = csll_create(NULL);
    csll_append(g_player.pp_anim_arr[DIR_IDLE], pa_idle0);

    g_player.pp_anim_arr[DIR_RIGHT] = csll_create(NULL);
    csll_append(g_player.pp_anim_arr[DIR_RIGHT], pa_rwalk0);
    csll_append(g_player.pp_anim_arr[DIR_RIGHT], pa_rwalk1);
    csll_append(g_player.pp_anim_arr[DIR_RIGHT], pa_rwalk2);
    csll_append(g_player.pp_anim_arr[DIR_RIGHT], pa_rwalk3);

    g_player.pp_anim_arr[DIR_LEFT] = csll_create(NULL);
    csll_append(g_player.pp_anim_arr[DIR_LEFT], pa_lwalk0);
    csll_append(g_player.pp_anim_arr[DIR_LEFT], pa_lwalk1);
    csll_append(g_player.pp_anim_arr[DIR_LEFT], pa_lwalk2);
    csll_append(g_player.pp_anim_arr[DIR_LEFT], pa_lwalk3);

    player_idle();

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
    // change animation call to walk right
    g_player.dir         = DIR_RIGHT;
    g_player.p_curr_anim = g_player.pp_anim_arr[DIR_RIGHT]->p_head;
}

void player_walk_left (void)
{
    // change animation csll to walk left
    g_player.dir         = DIR_LEFT;
    g_player.p_curr_anim = g_player.pp_anim_arr[DIR_LEFT]->p_head;
}

void player_idle (void)
{
    g_player.dir         = DIR_IDLE;
    g_player.p_curr_anim = g_player.pp_anim_arr[DIR_IDLE]->p_head;
}

void player_step (void)
{
    g_player.p_curr_anim = g_player.p_curr_anim->p_next;
    player_anim_frame_t * p_curr_anim
        = (player_anim_frame_t *)g_player.p_curr_anim->p_data;
    g_player.pos.x += p_curr_anim->offset.x;
    g_player.pos.y += p_curr_anim->offset.y;

    // (void)fprintf(stderr,
    //               "%c%c%c       %d,%d\n",
    //               p_curr_anim->p_arr[0],
    //               p_curr_anim->p_arr[1],
    //               p_curr_anim->p_arr[2],
    //               g_player.pos.x,
    //               g_player.pos.y);
}

char * player_export (void)
{
    player_anim_frame_t * p_curr_anim
        = (player_anim_frame_t *)g_player.p_curr_anim->p_data;
    gp_player_arr[6] = p_curr_anim->p_arr[0];
    gp_player_arr[7] = p_curr_anim->p_arr[1];
    gp_player_arr[8] = p_curr_anim->p_arr[2];
    return (gp_player_arr);
}

player_t * player_get (void)
{
    return (&g_player);
}

void player_destroy (void)
{
    csll_destroy(&(g_player.pp_anim_arr[DIR_IDLE]));
    csll_destroy(&(g_player.pp_anim_arr[DIR_RIGHT]));
    csll_destroy(&(g_player.pp_anim_arr[DIR_LEFT]));
    free(g_player.pp_anim_arr);
}