// #include "../include/main.h"

// typedef enum movement_keys_t
// {
//     MOVEMENT_KEY_UP    = 119,
//     MOVEMENT_KEY_DOWN  = 115,
//     MOVEMENT_KEY_RIGHT = 100,
//     MOVEMENT_KEY_LEFT  = 97
// } movement_keys_t;

// static _Atomic bool gb_run = true;
// static void         sighandler (int signum);

// static void sighandler (int signum)
// {
//     if (SIGINT == signum)
//     {
//         gb_run = false;
//     }
// }

// static void install_sighandler (void)
// {
//     struct sigaction sigaction_handler = { .sa_handler = sighandler };
//     sigaction(SIGINT, &sigaction_handler, NULL);
// }

// int main (void)
// {
//     install_sighandler();

//     int        width    = 100;
//     int        height   = 10;
//     screen_t * p_screen = screen_init(width, height);
//     screen_clear(p_screen);
//     player_init();
//     // char * p_player_arr = player_export();

//     // for (int y = 0; y < 3; y++)
//     // {
//     //     for (int x = 0; x < 3; x++)
//     //     {
//     //         screen_modify(p_screen,
//     //                       (point_t) { .x = x, .y = y },
//     //                       p_player_arr[(y * 3) + x]);
//     //     }
//     // }

//     // screen_display(p_screen);

//     // screen_clear(p_screen);

//     while (gb_run)
//     {
//         char    chr[3]     = { 0 };
//         ssize_t bytes_read = 0;
//         bytes_read         = read(STDIN_FILENO, &chr, 3);

//         if (0 > bytes_read)
//         {
//             player_idle();
//             player_t * p_player     = player_get();
//             char *     p_player_arr = player_export();

//             for (int y = 0; y < 3; y++)
//             {
//                 for (int x = 0; x < 3; x++)
//                 {
//                     screen_modify(
//                         p_screen,
//                         (point_t) { .x = x + p_player->pos.x, .y = y },
//                         p_player_arr[(y * 3) + x]);
//                 }
//             }

//             screen_display(p_screen);
//             continue;
//         }

//         if (3 == chr[0])
//         {
//             printf("Exiting...\n");
//             break;
//         }

//         switch (chr[0])
//         {
//             case MOVEMENT_KEY_UP:
//                 break;
//             case MOVEMENT_KEY_DOWN:
//                 break;
//             case MOVEMENT_KEY_RIGHT:
//                 player_walk_right();
//                 break;
//             case MOVEMENT_KEY_LEFT:
//                 player_walk_left();
//                 break;
//             default:
//                 // player_idle();
//                 continue;
//         }

//         screen_clear(p_screen);
//         player_t * p_player     = player_get();
//         char *     p_player_arr = player_export();

//         for (int y = 0; y < 3; y++)
//         {
//             for (int x = 0; x < 3; x++)
//             {
//                 screen_modify(p_screen,
//                               (point_t) { .x = x + p_player->pos.x, .y = y },
//                               p_player_arr[(y * 3) + x]);
//             }
//         }

//         screen_display(p_screen);

//         // screen_display(p_screen);
//         usleep(100000);
//     }

//     screen_destroy(&p_screen);
//     // player_print();
//     // sleep(1);
//     // player_walk_right();
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     // player_walk_left();
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     // player_idle();
//     // term_clear();
//     // player_print();
//     // sleep(1);
//     return 0;
// }