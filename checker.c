#include <checker.h>

int     ft_atoi(char *str)
{
    int value;
    int negative;

    value = 0;
    negative = (*str == '-') ? -1 : 1;
    if (*str == '-')
        str++;
    while (*str != 0)
        value = value * 10 + (*str++ - '0');
    return (value * negative);
}

int     valid_int(char *str)
{
    if (*str == '-')
        str++;
    while (*str != 0)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int     main(int argc, char **argv)
{
    int     i;
    int     *iargs;
    char    *str;

    i = 0;
    if (argc < 2)
        ft_putstr("Error\n");
    else
    {
        iargs = (int *)malloc(sizeof(int) * argc);
        while (argc > 1)
        {
            if (!valid_int(argv[--argc]))
            {
                ft_putstr("Error\n");
                return (0);
            }
            iargs[i++] = ft_atoi(argv[argc]);
        }
        iargs[i] = '\0';
    }
    // while(get_next_line(0, &str))
    // {
        
    // }
    free(iargs);
}
