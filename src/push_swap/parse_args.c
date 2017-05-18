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
		//printf("test\n");
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
	//printf("string: %s\n", str);
	if (ft_max_atoi(str) > INT_MAX || ft_max_atoi(str) < INT_MIN)
		return (0);
	//printf("test\n");
	if (*str == '-')
		str++;
	//printf("test\n");
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
	char	**args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	args = ft_strsplit(arg, ' ');
	//printf("string: %s\n", args[i]);
	length = get_length(args);
	//printf("string: %s\n", args[i]);
	printf("length: %i\n", length);
	while (i < length)
	{
		if (!valid_int(args[i]))
			put_error();
		//printf("test\n");
		if (!check_duplicates(ledger, ft_atoi(args[i])))
			put_error();
		//printf("test\n");
		if (ledger->asize == 0)
		{
			//printf("test\n");
			ledger->a->tail = new_nodelst(ft_atoi(args[i]));
			ledger->a->head = ledger->a->tail;
		}
		else
		{
			//printf("test\n");
			insert_node(ledger->a->head, ledger->a, ft_atoi(args[i]));
		}
		//printf("test\n");
		i++;
		ledger->asize++;
		//printf("test\n");
	}
	ledger->a->head->prev = ledger->a->tail;
	ledger->a->tail->next = ledger->a->head;
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
