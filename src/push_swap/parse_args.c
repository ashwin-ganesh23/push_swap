#include "../includes/push_swap.h"

void    parse_pargs(t_ledger *ledger, int argc, char **argv)
{
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
    }
	ledger->a->head->prev = ledger->a->tail;
	ledger->a->tail->next = ledger->a->head;
	set_maxmin(ledger);
}

void 	parse_arg(t_ledger *ledger, char *arg)
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
		if (!valid_int(args[length - i - 1]))
			put_error();
		if (!check_duplicates(ledger, ft_atoi(args[length - i - 1])))
			put_error();
		if (ledger->asize == 0)
		{
			ledger->a->tail = new_nodelst(ft_atoi(args[length - i - 1]));
			ledger->a->head = ledger->a->tail;
		}
		else
		{
			insert_node(ledger->a->head, ledger->a, ft_atoi(args[length - i - 1]));
		}
		i++;
		ledger->asize++;
	}
	ledger->a->head->prev = ledger->a->tail;
	ledger->a->tail->next = ledger->a->head;
}

void 	set_maxmin(t_ledger *ledger)
{
	int		max;
	int		min;
	t_node	*tmp;

	tmp = ledger->a->head;
	max = tmp->data;
	min = tmp->data;
	tmp = tmp->next;
	while (tmp->data != ledger->a->head->data)
	{
		if (tmp->data > max)
			max = tmp->data;
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	ledger->a->max = get_nth(ledger->a, get_dindex(ledger->a, max, ledger->asize));
	ledger->a->min = get_nth(ledger->a, get_dindex(ledger->a, min, ledger->asize));
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

static int	space(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}


ssize_t		ft_max_atoi(char *str)
{
	size_t	num;
	int		sign;
	int		p;

	num = 0;
	sign = 1;
	p = 0;
	while (space(*str))
		str++;
	if (str[p] == '-')
	{
		sign = -1;
		p++;
	}
	else if (str[p] == '+')
		p++;
	while ((str[p] >= '0') && (str[p] <= '9'))
	{
		num = num * 10 + (str[p] - '0');
		p++;
	}
	num = num * sign;
	return (num);
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
