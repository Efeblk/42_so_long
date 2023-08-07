#include "so_long.h"

void bercheck (char *mapname)
{
    int i;
    i = 0;
    i = ft_strlen(mapname);
    if (i <= 4)
        exitor();
    else
        is_ber(mapname, i - 1);
}

void is_ber(char *mapname, int end)
{
    char *ber;
    char *mapend;

    ber = ".ber";
    mapend = mapname + (end - 3);

    while (*mapend++ && *ber++)
    {
        if (*mapend != *ber)
            exitor();
    }
}