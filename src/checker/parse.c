#include "../includes/checker.h"

void    parse_args(t_stack *root, int length, char **argv)
{
	int		i;

	i = 0;
	while (i < length)
	{
		if (!valid_int(argv[i + 1]))
			put_error();
		if (!check_duplicates(root, ft_atoi(argv[i + 1])))
			put_error();
		root->a[length] = '\0';
		root->a[length - i - 1] = ft_atoi(argv[i + 1]);
		i++;
		root->asize++;
	}
}

void 	parse_arg(t_stack *root, char *arg)
{
	char	**args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	args = ft_strsplit(arg, ' ');
	length = get_length(args);
	while (i < length)
	{
		if (!valid_int(args[i]))
			put_error();
		if (!check_duplicates(root, ft_atoi(args[i])))
			put_error();
		root->a[length] = '\0';
		root->a[length - i - 1] = ft_atoi(args[i]);
		i++;
		root->asize++;
	}
	root->a[i] = '\0';
}
