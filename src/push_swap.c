#include "push_swap.h"

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

void    parse_pargs(t_ledger *root, int argc, char **argv)
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

t_node	*new_nodelst()
{
	t_node 	*node;

	if ((node = (t_node *)malloc(sizeof(*node))) == NULL)
		return (0);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int		insert_node(t_node *node, t_list *master)
{
	t_node *temp;

	if ((temp = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (0);
	temp->next = NULL;
	temp->prev = NULL;
	if (!node)
		node = temp;
	else
	{
		temp->next = node;
		node->prev = temp;
		master->head = temp;
	}
	temp->next = node;
	node = temp;
	return (1);
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

int 	pick_score(t_stack *ledger)
{
	int 	i;
	int		min;
	int		imin;
	t_node 	tmp;

	i = 0;
	imin = 0;
	min = 10000;
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

void	calculate_scores(t_stack *ledger)
{
	t_node 	*temp;
	t_node	*tmp;
	int 	min;
	int 	i;

	min = 0;
	i = 0;
	temp = ledger->a->head;
	tmp = ledger->b->head;
	while (temp != NULL)
	{
		if (bsize <= 2)
			return (0);
		else
		{
			min = 0;
			if (temp->pos < tmp->pos)
			{
				while (temp->pos < tmp->pos)
				{
					tmp = tmp->next;
					min++;
				}
			}
			else if (temp->pos > tmp->pos)
			{
				while (temp->pos > tmp->pos)
				{
					tmp = tmp->next;
					min++;
				}
			}
			i = (i > (ledger->asize / 2)) ? i: ledger->asize - i;
			min = (min > (ledger->bsize / 2) ? i : ledger->asize - i);
			temp->score = min + i;
		}
		if (temp->next != NULL)
			temp = temp->next;
		i++;
	}
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

void 	solver(t_ledger *root)
{
	int 	solved;
	int 	index;

	solved = 0;
	if (root->asize < 5)
		small_solver();
	else
	{
		while (!solved)
		{
			calculate_scores(root);
			index = pick_score(root);
			put_moves();
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
