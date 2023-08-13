#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        t_map map;
        bercheck(argv[1]);
        readmap(argv[1], 1, &map);
        readmap(argv[1], 0, &map);
    }
    return 0;
}
