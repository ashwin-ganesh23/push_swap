#include "checker.h"

void 	(*g_funcs[11])(t_stack *stk) =
{
	&sa,
	&sb,
	&ss,
	&pa,
	&pb,
	&ra,
	&rb,
	&rr,
	&rra,
	&rrb,
	&rrc,
};

void		sa(t_stack *stk)
{
	int 	tmp;

	if (stk->asize > 1)
	{
		tmp = stk->a[stk->asize];
		stk->a[stk->asize] = stk->a[stk->asize - 1];
		stk->a[stk->asize - 1] = tmp;
	}
}

void		sb(t_stack *stk)
{
	int 	tmp;

	if (stk->bsize > 1)
	{
		tmp = stk->b[stk->bsize];
		stk->b[stk->bsize] = stk->b[stk->bsize - 1];
		stk->b[stk->bsize - 1] = tmp;
	}
}

void		ss(t_stack *stk)
{
	sa(stk);
	sb(stk);
}

void		pa(t_stack *stk)
{
	int 	tmp;

	if (stk->bsize > 0)
	{
		tmp = stk->b[bsize];
		stk->b[bsize--] = 0;
		stk->a[asize++] = tmp;
	}
}

void		pb(t_stack *stk)
{
	int 	tmp;

	if (stk->asize > 0)
	{
		tmp = stk->a[asize];
		stk->a[asize--] = 0;
		stk->b[bsize++] = tmp;
	}
}

void		ra(t_stack *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->asize > 1)
	{
		tsize = asize;
		tmp = stk->a[asize];
		while (tsize > 1)
			stk->a[tsize--] = stk->a[tsize - 1];
		stk->a[0] = tmp;
	}
}

void		rb(t_stack *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->bsize > 1)
	{
		tsize = bsize;
		tmp = stk->b[bsize];
		while (tsize > 1)
			stk->b[tsize--] = stk->b[tsize - 1];
		stk->b[0] = tmp;
	}
}

void		rr(t_stack *stk)
{
	ra(stk);
	rb(stk);
}

void		rra(t_stack *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->asize > 1)
	{
		tsize = 0;
		tmp = stk->a[0];
		while (tsize < asize)
			stk->a[tsize++] = stk->a[tsize + 1];
		stk->a[asize] = tmp;
	}
}

void		rrb(t_stack *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->bsize > 1)
	{
		tsize = 0;
		tmp = stk->b[0];
		while (tsize < bsize)
			stk->b[tsize++] = stk->b[tsize + 1];
		stk->b[bsize] = tmp;
	}
}

void		rrr(t_stack *stk)
{
	rra(stk);
	rrb(stk);
}

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

void 	check_instruction(t_stack *root, char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) > 3 || ft_strlen(str) < 2)
		put_error();
	while (i < 11 && ft_strncmp(str, root->instructions[i], 3) != 0)
		i++;
	if (i == 11)
		put_error();
	(*g_funcs[i])(root);
}

void    parse_args(t_stack *root, int argc, char **argv)
{
	int 	i;

	i = 0;
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

int 	initialize_stk(t_stack *root, int argc)
{
	if ((root->a = (int *)malloc(sizeof(int) * argc)) == NULL)
		return (0);
	if ((root->b = (int *)malloc(sizeof(int) * argc)) == NULL)
		return (0);
	root->asize = argc - 1;
	root->instructions[0] = "sa\0";
	root->instructions[1] = "sb\0";
	root->instructions[2] = "ss\0";
	root->instructions[3] = "pa\0";
	root->instructions[4] = "pb\0";
	root->instructions[5] = "ra\0";
	root->instructions[6] = "rb\0";
	root->instructions[7] = "rr\0";
	root->instructions[8] = "rra";
	root->instructions[9] = "rrb";
	root->instructions[10] = "rrr";
	return (1);
}

int     main(int argc, char **argv)
{
	t_stack root;
	char    *str;
	int 	fd;

	fd = 0;
	if (argc < 2)
		exit (0);
	if (!initialize_stk(&root, argc))
		return (0);
	parse_args(&root, argc, argv);
	while (get_next_line(fd, &str) == 1)
	{
		check_instruction(&root, str);
		printf("%s\n", str);
	}
	// check_solution();
    return (0);
}



	// for (int x = 0; x < i; x++)
	// {
	// 	printf("%d\n", root->a[x]);
	// }
