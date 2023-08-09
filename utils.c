
#include "so_long.h"

int ft_strlen1 (char *c)
{
    int i;
    i = 0;
    while (c[i] && c[i] != '\n')
       i++;
    return(i);
}

void exitor ()
{
    write(1, "Error\n", 6);
    exit(1);
}