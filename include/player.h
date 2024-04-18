#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include "point.h"

#define HEAD_IDLE    " %c \n"
#define BODY_IDLE    "%c%c%c\n"
#define RWALK_FIRST  " %c%c\n"
#define RWALK_SECOND "%c %c\n"
#define LWALK_FIRST  "%c%c\n"
#define LWALK_SECOND "%c %c\n"

/**
 * @brief Enum for player icons
 *
 */
typedef enum player_limbs_t
{
    HEAD              = 'o',
    BODY              = '|',
    LARM_IDLE         = '/',
    RARM_IDLE         = '\\',
    LLEG_IDLE         = '/',
    RLEG_IDLE         = '\\',
    LLEG_LWALK_FIRST  = '/',
    RLEG_LWALK_FIRST  = '<',
    LLEG_LWALK_SECOND = '<',
    RLEG_LWALK_SECOND = '\\',
    LLEG_RWALK_FIRST  = '>',
    RLEG_RWALK_FIRST  = '\\',
    LLEG_RWALK_SECOND = '/',
    RLEG_RWALK_SECOND = '>',
    LLEG_JUMP_PREP    = '<',
    RLEG_JUMP_PREP    = '>',
} player_limbs_t;

/**
 * @brief Enum for player directions
 *
 */
typedef enum player_dir_t
{
    DIR_LEFT  = -1,
    DIR_IDLE  = 0,
    DIR_RIGHT = 1,
} player_dir_t;

// dir -1 is left and 1 is right
// dir iter is used to switch legs, 0 for first, 1 for second
typedef struct player_t
{
    char    head[1];
    char    body[1];
    char    larm[1];
    char    rarm[1];
    char    lleg[1];
    char    rleg[1];
    int     dir;
    int     dir_iter;
    point_t pos;
} player_t;

void player_print (void);
void player_walk_right (void);
void player_walk_left (void);
void player_idle (void);

#endif // PLAYER_H

/*** end of file ***/