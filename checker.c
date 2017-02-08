#include "checker.h"

intmax_t	ft_max_atoi(char *str)
{
    size_t	value;
    int 	negative;

    value = 0;
    negative = (*str == '-') ? -1 : 1;
    if (*str == '-')
        str++;
    while (*str != 0)
        value = value * 10 + (*str++ - '0');
    return ((size_t)value * negative);
}

int     valid_int(char *str)
{
	if (ft_max_atoi(str) > INT_MAX || ft_max_atoi(str) < INT_MIN)
		return (0);
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

void	put_error()
{
	ft_putstr("Error\n");
	exit (0);
}

int 	check_duplicates(t_stack *root, int n)
{
	int 	i;

	i = 0;
	while (root->a[i] != 0)
	{
		if (root->a[i++] == n)
			return (0);
	}
	return (1);
}

int 	check_instructions(char *str)
{
	if (ft_strlen(str) > 3)
		return (0);
	if (!(ft_strncmp(str, "sa", 2) || ft_strncmp(str, "ss", 2)))
		return (0);
	return (1);
}

void    parse_args(t_stack *root, int argc, char **argv)
{
	int 	i;

	i = 0;
	root->a = (int *)malloc(sizeof(int) * argc);
	root->asize = argc - 1;
	while (argc > 1)
	{
		if (!valid_int(argv[--argc]))
			put_error();
		if (!check_duplicates(root, ft_atoi(argv[argc])))
			put_error();
		root->a[i++] = ft_atoi(argv[argc]);
	}
	root->a[i] = '\0';
}

int     main(int argc, char **argv)
{
	t_stack root;
	char    *str;
	int 	fd;

	fd = 0;
	if (argc < 2)
		exit (0);
	parse_args(&root, argc, argv);
	printf("sa\n");
	printf("sb\n");
	while (get_next_line(fd, &str) == 1)
	{
		printf("hello");
		if (!check_instructions(str))
			put_error();
	}
	//free(iargs);
    return (0);
}



	// for (int x = 0; x < i; x++)
	// {
	// 	printf("%d\n", root->a[x]);
	// }