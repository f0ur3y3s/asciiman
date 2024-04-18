#ifndef SCREEN_H
#define SCREEN_H

#include "point.h"
#include "term.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define SCREEN_EMPTY " "

typedef enum screen_constants_t
{
    MIN_WIDTH  = 10,
    MIN_HEIGHT = 10,
} screen_constants_t;

typedef enum screen_retval_t
{
    S_ERR = -1,
    S_OK  = 0,
    S_UPDATE,
} screen_retval_t;

typedef struct screen_t
{
    char * pp_display_arr;
    char * pp_buffer_arr;
    int    rows;
    int    cols;
} screen_t;

screen_t * screen_init (int cols, int rows);
int        screen_destroy (screen_t ** pp_screen);

int screen_update (screen_t * p_screen);
int screen_modify (screen_t * p_screen, point_t pos, char new_char);

#endif // SCREEN_H

/*** end of file ***/