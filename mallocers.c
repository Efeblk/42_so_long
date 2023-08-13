#include "so_long.h"

void mallocplayer(t_game *game)
{
    game->player->player_height = 0;
    game->player->player_img = NULL;
    game->player->player_width = 0;
}