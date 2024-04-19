#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include "point.h"
#include "csll.h"

// #define HEAD_IDLE    " %c \n"
// #define BODY_IDLE    "%c%c%c\n"
// #define RWALK_FIRST  " %c%c\n"
// #define RWALK_SECOND "%c %c\n"
// #define LWALK_FIRST  "%c%c\n"
// #define LWALK_SECOND "%c %c\n"
#define NUM_ANIM 3

/**
 * @brief Enum for player icons
 *
 */
typedef enum player_limbs_t
{
    HEAD         = 'o',
    BODY         = '|',
    LEG_CENTER   = '|',
    LARM_IDLE    = '/',
    RARM_IDLE    = '\\',
    LLEG_IDLE    = '/',
    RLEG_IDLE    = '\\',
    RWALK_BENT   = '>',
    LWALK_BENT   = '<',
    PLAYER_EMPTY = ' ',
} player_limbs_t;

typedef struct player_anim_frame_t
{
    char *  p_arr;
    point_t offset;
} player_anim_frame_t;

/**
 * @brief Enum for player directions
 *
 */
typedef enum player_dir_t
{
    DIR_IDLE  = 0,
    DIR_RIGHT = 1,
    DIR_LEFT  = 2,
} player_dir_t;

// dir -1 is left and 1 is right
// dir iter is used to switch legs, 0 for first, 1 for second
typedef struct player_t
{
    char          head[1];
    char          body[1];
    char          larm[1];
    char          rarm[1];
    char          lleg[1];
    char          rleg[1];
    int           dir;
    point_t       pos;
    csll_t **     pp_anim_arr;
    csll_node_t * p_curr_anim;
} player_t;

void       player_init (void);
void       player_print (void);
void       player_step (void);
void       player_walk_right (void);
void       player_walk_left (void);
void       player_idle (void);
char *     player_export (void);
player_t * player_get (void);
void       player_destroy (void);

#endif // PLAYER_H

/*** end of file ***/