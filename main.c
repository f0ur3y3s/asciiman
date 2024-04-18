#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/player.h"

int main (void)
{
    player_print();
    player_walk_right();
    player_print();
    player_print();
    player_print();
    player_print();
    player_walk_left();
    player_print();
    player_print();
    player_print();
    player_print();
    player_idle();
    player_print();
    return 0;
}