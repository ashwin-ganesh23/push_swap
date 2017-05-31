#include "../includes/checker.h"

int 	check_duplicates(t_stack *root, int n)
{
	int 	i;

	i = root->asize - 1;
	while (i >= 0)
	{
		if (root->a[i--] == n)
			return (0);
	}
	return (1);
}

void 	check_instruction(t_stack *root, char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) > 3 || ft_strlen(str) < 2)
		put_error();
	while (i < 11 && ft_strncmp(str, root->instructions[i], 4) != 0)
		i++;
	if (i == 11)
		put_error();
	(*g_funcs[i])(root);
}

int 	check_solution(t_stack *root)
{
	int 	tmp;
	size_t 	tsize;

	tsize = root->asize - 1;
	while (tsize > 0)
	{
		tmp = root->a[tsize];
		if (tmp > root->a[tsize - 1])
		{
			ft_putstr("KO\n");
			return (0);
		}
		tsize--;
	}
	ft_putstr("OK\n");
	return (1);
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

ssize_t		ft_max_atoi(char *str)
{
    size_t	value;
    int 	negative;

    value = 0;
    negative = (*str == '-') ? -1 : 1;
    if (*str == '-')
        str++;
    while (*str != 0)
        value = value * 10 + (*str++ - '0');
    return (value * negative);
}
