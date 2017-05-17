#include "../includes/push_swap.h"

void    parse_pargs(t_ledger *ledger, int argc, char **argv)
{
	int 	i;

	i = 0;
	if (argc == 2)
	{
		parse_arg(ledger, argv[1]);
		argc--;
	}
	while (argc > 1)
	{
		if (!valid_int(argv[--argc]))
			put_error();
		if (!check_duplicates(ledger, ft_atoi(argv[argc])))
			put_error();
		//printf("test\n");
		if (ledger->asize == 0)
		{
			ledger->a->tail = new_nodelst(ft_atoi(argv[argc]));
			ledger->a->head = ledger->a->tail;
		}
		else
		{
			insert_node(ledger->a->head, ledger->a, ft_atoi(argv[argc]));
		}
		ledger->asize++;
		printf("test\n");
    }
	ledger->a->head->prev = ledger->a->tail;
	ledger->a->tail->next = ledger->a->head;
}

int 	check_duplicates(t_ledger *root, int n)
{
	t_node	*tmp;

	tmp = NULL;
	if (root->asize == 0)
		return (1);
	else
		tmp = root->a->head;
	while (tmp->data != root->a->tail->data)
	{
		if (tmp->data == n)
			return (0);
		if (tmp->data != root->a->tail->data)
			tmp = tmp->next;
		else
			tmp = NULL;
	}
	if (tmp->data == n)
		return (0);
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

void 	parse_arg(t_ledger *ledger, char *arg)
{
	char **args;

	args = ft_strsplit(arg, ' ');
	while (*args)
	{
		if (!valid_int(*args))
			put_error();
		if (!check_duplicates(ledger, ft_atoi(*args)))
			put_error();
		if (ledger->a->tail == NULL)
		{
			ledger->a->tail = new_nodelst(ft_atoi(*args));
			ledger->a->head = ledger->a->tail;
		}
		else
			insert_node(ledger->a->head, ledger->a, ft_atoi(*args));
		args++;
		ledger->asize++;
	}
	ledger->a->head->prev = ledger->a->tail;
	ledger->a->tail->next = ledger->a->head;
}
