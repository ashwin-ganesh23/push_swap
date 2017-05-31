#include "../includes/checker.h"

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
	&rrr,
};

void	put_error()
{
	ft_putstr("Error\n");
	exit (0);
}

int		get_length(char **args)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = args[i];
	while (tmp != NULL)
	{
		i++;
		if (args[i] == NULL)
			return (i);
		tmp = args[i];
	}
	return (i);
}

void 	print_stacks(t_stack *root)
{
	size_t 	size;

	size = (root->asize > root->bsize) ? root->asize : root->bsize;
	printf("\nChecker visualization:\n");
	while (size > 0)
	{
		size--;
		if (root->bsize > size && root->asize > size)
			printf("%i\t%i\n", root->a[size], root->b[size]);
		else if (root->asize > size)
			printf("%i\n", root->a[size]);
		else if (root->bsize > size)
			printf("\t%i\n", root->b[size]);
	}
	printf("_\t_\n");
	printf("a\tb\n");
}

int     main(int argc, char **argv)
{
	t_stack root;
	char    *str;
	int 	fd;
	int		length;

	fd = 0;
	length = 0;
	if (argc < 2)
		exit (0);
	if (argc == 2)
		length = get_length(ft_strsplit(argv[1], ' '));
	else
		length = argc - 1;
	if (!initialize_stk(&root, length))
		return (0);
	if (argc == 2 && length != 1)
		parse_arg(&root, argv[1]);
	else
		parse_args(&root, length, argv);
	while (get_next_line(fd, &str) == 1)
	{
		check_instruction(&root, str);
	}
	check_solution(&root);
    return (0);
}
