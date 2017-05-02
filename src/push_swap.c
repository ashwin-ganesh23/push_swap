#include "push_swap.h"

void		sa(t_ledger *stk)
{
	t_node	*tmp;

	if (stk->asize > 1)
	{
		tmp = stk->a->head;
		stk->a[stk->asize - 1] = stk->a[stk->asize - 2];
		stk->a[stk->asize - 2] = tmp;
	}
}

void		sb(t_ledger *stk)
{
	int 	tmp;

	if (stk->bsize > 1)
	{
		tmp = stk->b[stk->bsize - 1];
		stk->b[stk->bsize - 1] = stk->b[stk->bsize - 2];
		stk->b[stk->bsize - 2] = tmp;
	}
}

void		ss(t_ledger *stk)
{
	sa(stk);
	sb(stk);
}

void		pa(t_ledger *stk)
{
	int 	tmp;

	if (stk->bsize > 0)
	{
		stk->bsize--;
		tmp = stk->b[stk->bsize];
		stk->b[stk->bsize] = 0;
		stk->a[stk->asize++] = tmp;
	}
}

void		pb(t_ledger *stk)
{
	int 	tmp;

	if (stk->asize > 0)
	{
		stk->asize--;
		tmp = stk->a[stk->asize];
		stk->a[stk->asize] = 0;
		stk->b[stk->bsize++] = tmp;
		if (stk->min != NULL && stk->max != NULL)
		{
			if (stk->min->data > tmp)
				stk->min = stk->b[stk->bsize-1];
			if (stk->max->data > tmp)
			 	stk->max = stk->b[stk->bsize-1];
		}
		if (stk->min == NULL && stk->max == NULL)
		{
			stk->min = stk->b[stk->bsize-1];
			stk->max = stk->b[stk->bsize-1];
		}
	}
}

void		ra(t_ledger *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->asize > 1)
	{
		tsize = stk->asize;
		tmp = stk->a[stk->asize];
		while (tsize > 1)
		{
			stk->a[tsize] = stk->a[tsize - 1];
			tsize--;
		}
		stk->a[0] = tmp;
	}
}

void		rb(t_ledger *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->bsize > 1)
	{
		tsize = stk->bsize;
		tmp = stk->b[stk->bsize];
		while (tsize > 1)
		{
			stk->b[tsize] = stk->b[tsize - 1];
			tsize--;
		}
		stk->b[0] = tmp;
	}
}

void		rr(t_ledger *stk)
{
	ra(stk);
	rb(stk);
}

void		rra(t_ledger *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->asize > 1)
	{
		tsize = 0;
		tmp = stk->a[0];
		while (tsize < stk->asize)
		{
			stk->a[tsize] = stk->a[tsize + 1];
			tsize++;
		}
		stk->a[stk->asize] = tmp;
	}
}

void		rrb(t_ledger *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->bsize > 1)
	{
		tsize = 0;
		tmp = stk->b[0];
		while (tsize < stk->bsize)
		{
			stk->b[tsize] = stk->b[tsize + 1];
			tsize++;
		}
		stk->b[stk->bsize] = tmp;
	}
}

void		rrr(t_ledger *stk)
{
	rra(stk);
	rrb(stk);
}

void 	(*g_funcs[11])(t_ledger *stk) =
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

void	put_error()
{
	ft_putstr("Error\n");
	exit (0);
}

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
		}
		insert_node(ledger->a->head, ledger->a, ft_atoi(argv[argc]));
	}
}

t_node	*new_nodelst(int input)
{
	t_node 	*node;

	if ((node = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (0);
	node->next = NULL;
	node->prev = NULL;
	node->data = input;
	return (node);
}

int		insert_node(t_node *head, t_list *master, int input)
{
	t_node *temp;

	if ((temp = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (0);
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = input;
	if (!head)
		head = temp;
	else
	{
		temp->next = head;
		head->prev = temp;
		master->head = temp;
	}
	temp->next = node;
	node = temp;
	return (0);
}

t_node	*split(t_node *head)
{
    t_node	*fast;
	t_node	*slow;
	t_node	*temp;

	fast = head;
	slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    temp = slow->next;
    slow->next = NULL;
    return (temp);
}

t_node	*merge(t_node *first, t_node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    if (first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

t_node	*merge_sort(t_node *head)
{
	t_node	*second;

	if (!head || !head->next)
        return (head);
    second = split(head);
    head = merge_sort(head);
    second = merge_sort(second);
    return (merge(head,second));
}

void 	set_place(t_stack *ledger)
{
	int 	i;
	t_node	*temp;
	t_node	*tmp;
	t_node 	*t;

	i = 0;
	tmp = ledger->a->head;
	temp = merge_sort(tmp);
	while (i < ledger->asize)
	{
		t = temp;
		while (tmp->data != t->data)
			t = t->next;
		tmp->pos = i++;
		tmp = tmp->next;
	}
}

int 	initialize_ledger(t_stack *ledger, int argc)
{
	int 	i;

	i = 0;
	root->a = NULL;
	root->b = NULL;
	if ((root->a = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (0);
	if ((root->b = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (0);
	if ((root->instructions = (char**)malloc(sizeof(char*) * 11)) == NULL)
		return (0);
	while (i < 11)
	{
		if ((root->instructions[i++] = (char *)malloc(sizeof(char) * 4)) == NULL)
			return (0);
	}
	root->asize = argc - 1;
	root->bsize = 0;
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

int 	pick_score(t_stack *ledger)
{
	int 	i;
	int		min;
	int		imin;
	t_node 	tmp;

	i = 0;
	imin = 0;
	min = 1000;
	tmp = ledger->a->head;
	while (i < ledger->asize)
	{
		if (tmp->score < min)
		{
			min = tmp->score;
			imin = i;
		}
		i++;
	}
	return (imin);
}

int		calculate_score(t_stack *ledger, int i)
{
	t_node 	*stacka;
	t_node	*stackb;
	t_node	*tailb;
	int 	min;

	min = 0;
	stacka = ledger->a->head;
	stackb = ledger->b->head;
	tailb = ledger->b->tail;
	if (bsize <= 2)
		return (0);
	else
	{
		min = 0;
		if ((stacka->pos < stackb->pos && stacka->pos > tailb->pos) ||
		 (stacka->pos > stackb->pos && stacka->pos < tailb->pos))
		 	return (min);
		if (stacka->pos > stackb->pos)
		{
			while (stacka->pos > stackb->pos)
			{
				stackb = stackb->next;
				min++;
			}
		}
		while (stacka->pos > stackb->pos)
		{
			stackb = stackb->next;
			min++;
		}
		i = (i > (ledger->asize / 2)) ? i: ledger->asize - i;
		min = (min > (ledger->bsize / 2) ? i : 0,ledger->asize - i);
		stacka->score = min + i;
	}
	i++;

}

void 	small_solver()
{

}

void 	big_solver()
{

}

void 	solver(t_ledger *root)
{
	int 	solved;
	int 	index;

	solved = 0;
	if (root->asize < 5)
		small_solver(root);
	else
	{
		big_solver(root);
		if (root->bsize < 2)
		{

		}
		while (!solved)
		{

			calculate_score(root);
			index = pick_score(root);
		}
	}
}

int		main(int argc, char **argv)
{
	t_ledger root;

	if (argc < 2)
		exit(0);
	if (!initialize_ledger(&root, argc))
		return (0);
	parse_pargs(&root, argc, argv);
	set_place(&root);
	while (root.asize > 0)
	{
		print("%i\t", root.a->data);
		print("%i\n", root.a->pos);
		root.a = root.a->next;
	}
	solver(&root);
}
