#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        t_game *game;

        game = (t_game *)malloc(sizeof(t_game));
        mallocplayer(game);
        bercheck(argv[1]);
        readmap(argv[1], 1, game->map, game);
        readmap(argv[1], 0, game->map, game);
    }
    return 0;
}
