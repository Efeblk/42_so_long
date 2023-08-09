#include "so_long.h"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        bercheck(argv[1]);
        readmap(argv[1]);
    }
    return 0;
}
