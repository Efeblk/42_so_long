#include "so_long.h"

void mallocplayer(t_game *game)
{
    game->player = (t_player *)malloc(sizeof(t_player));
    game->player->player_height = 0;
    game->player->player_img = NULL;
    game->player->player_width = 0;
}