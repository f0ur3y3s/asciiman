#include "../include/screen.h"

screen_t * screen_init (int cols, int rows)
{
    screen_t * p_screen = NULL;

    if (MIN_WIDTH > cols || MIN_HEIGHT > rows)
    {
        goto EXIT;
    }

    p_screen = calloc(1, sizeof(screen_t));

    if (NULL == p_screen)
    {
        goto EXIT;
    }

    p_screen->pp_display_arr = (char *)calloc(cols * rows, sizeof(char));

    if (NULL == p_screen->pp_display_arr)
    {
        goto CLEANUP_SCREEN;
    }

    p_screen->pp_buffer_arr = (char *)calloc(cols * rows, sizeof(char));

    if (NULL == p_screen->pp_buffer_arr)
    {
        goto CLEANUP_DISPLAY;
    }

    p_screen->cols = cols;
    p_screen->rows = rows;
    term_uncook();
    term_clear();

    for (int i = 0; i < p_screen->cols * p_screen->rows; i++)
    {
        p_screen->pp_buffer_arr[i] = '.';
    }

    screen_update(p_screen);

    goto EXIT;

// CLEANUP_BUFFER:
//     free(p_screen->pp_buffer_arr);
CLEANUP_DISPLAY:
    free(p_screen->pp_display_arr);
CLEANUP_SCREEN:
    free(p_screen);
    p_screen = NULL;
EXIT:
    return (p_screen);
}

int screen_destroy (screen_t ** pp_screen)
{
    int status = S_ERR;

    if (NULL == pp_screen || NULL == *pp_screen
        || NULL == (*pp_screen)->pp_display_arr
        || NULL == (*pp_screen)->pp_buffer_arr)
    {
        goto EXIT;
    }

    free((*pp_screen)->pp_display_arr);
    free((*pp_screen)->pp_buffer_arr);
    free(*pp_screen);
    *pp_screen = NULL;
    term_clear();
    term_cook();

    status = S_OK;
EXIT:
    return (status);
}

int screen_update (screen_t * p_screen)
{
    int status = S_ERR;

    if (NULL == p_screen)
    {
        goto EXIT;
    }

    for (int row = 0; row < p_screen->rows; row++)
    {
        for (int col = 0; col < p_screen->cols; col++)
        {
            int acc_ptr = (row * p_screen->cols) + col;

            if (p_screen->pp_buffer_arr[acc_ptr]
                != p_screen->pp_display_arr[acc_ptr])
            {
                (void)fprintf(stderr, "Updating at x,y: %d, %d\n", col, row);
                term_gotoxy(col + 1, row + 1);
                (void)fprintf(stdout, "%c", p_screen->pp_buffer_arr[acc_ptr]);
                // update the character here
            }
            // printf("%c ", p_screen->pp_display_arr[acc_ptr]);
        }
    }

    // if needs to update, display new screen, copy display to buffer

    status = S_OK;

EXIT:
    return (status);
}

int screen_modify (screen_t * p_screen, point_t pos, char new_char)
{
    int status = S_ERR;

    if (NULL == p_screen)
    {
        goto EXIT;
    }

    if (p_screen->cols < pos.x || p_screen->rows < pos.y)
    {
        goto EXIT;
    }

    int acc_ptr = (pos.y * p_screen->cols) + pos.x;

    p_screen->pp_buffer_arr[acc_ptr] = new_char;

    status = S_OK;

EXIT:
    return (status);
}

// int main (void)
// {
//     screen_t * p_screen = screen_init(20, 10);
//     printf("col: %d height: %d\n", p_screen->col, p_screen->height);

//     for (int i = 0; i < p_screen->col * p_screen->height; i++)
//     {
//         if (i % p_screen->col == 5)
//         {
//             p_screen->pp_display_arr[i] = '|';
//         }
//         else
//         {
//             p_screen->pp_display_arr[i] = 'c';
//         }
//     }

//     screen_update(p_screen);
// }