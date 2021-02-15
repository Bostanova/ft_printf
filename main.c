#include "srcs/ft_printf.h"
#include <stdio.h>

int     main(void)
{
    int res1, res2;
    res1 = res2 = 0;
    int min = -2147483648;

    res1 = printf("%*.*d\n", 2, 0, min);
    res2 = ft_printf("%*.*d\n", 2, 0, min);
    printf("res1 = %d, res2 = %d\n", res1, res2);

    res1 = printf("|%--3d|\n", min);
    res2 = ft_printf("|%--3d|\n", min);
    printf("res1 = %d, res2 = %d\n", res1, res2);
    return (0);
}
