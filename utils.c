
#include "so_long.h"

int ft_strlen (char *c)
{
    int i;
    i = 0;
    while (c[i])
       i++;
    return(i);
}

void exitor ()
{
    write(1, "Error\n", 6);
    exit(1);
}