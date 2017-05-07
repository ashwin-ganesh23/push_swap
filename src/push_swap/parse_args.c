#include "push_swap.h"

void    parse_pargs(t_ledger *ledger, int argc, char **argv)
{
	int 	i;

	i = 0;
	while (argc > 1)
	{
		if (!valid_int(argv[--argc]))
			put_error();
		if (!check_duplicates(root, ft_atoi(argv[argc])))
			put_error();
		if (i = 0)
		{
			ledger->a->tail = new_nodelst(ft_atoi(argv[argc]));
			ledger->a->head = ledger->a->tail;
			root->a[i++] = ft_atoi(argv[argc]);
		}
		else
		{
			insert_node(ledger->a->head, ledger->a, ft_atoi(argv[argc]));
			root->a[i++] = ft_atoi(argv[arc]);
		}
    }
}

int 	check_duplicates(t_ledger *root, int n)
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
