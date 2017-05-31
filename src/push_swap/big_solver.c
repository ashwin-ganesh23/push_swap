#include "../includes/push_swap.h"

void 	big_solver(t_ledger *root)
{
	size_t index;

	print_stacks(root);
	while (root->bsize < 2 && !ordered(root))
	{
		put_instruction(root, 4);
		//print_stacks(root);
	}
	//print_stacks(root);
	while (root->asize > 0 && !ordered(root))
	{
		index = get_insert(root);
		//printf("index: %zu\n", index);
		insert_b(root, index);
		//print_stacks(root);
	}
	// if (root->asize <= 3)
	// 	sort_in_place(root);
	push_up_b(root, root->b, root->b->max);
	if (root->asize > 0 && ordered(root))
		push_inorder(root);
	else
		while (root->bsize > 0)
			put_instruction(root, 3);
	//print_stacks(root);
}

void 	push_inorder(t_ledger *root)
{
	set_maxmin(root);
	push_up_a(root, root->a, root->a->min);
	while (root->a->tail->data > root->b->head->data &&
	root->b->max->data < root->a->max->data)
		put_instruction(root, 8);
	while (root->bsize > 0)
	{
		while (root->a->tail->data > root->b->head->data &&
		root->a->tail != root->a->max)
		{
			put_instruction(root, 8);
			//print_stacks(root);
		}
		put_instruction(root, 3);
	}
	push_up_a(root, root->a, root->a->min);
}

void 	push_up_a(t_ledger *root, t_stack *stk, t_node *node)
{
	size_t	index;

	index = get_index(stk, node);
	while (index != 0)
	{
		if (index <= root->asize / 2)
		{
			put_instruction(root, 5);
			index--;
		}
		else if (index > root->asize / 2)
		{
			put_instruction(root, 8);
			index++;
			if (index == root->asize)
				index = 0;
		}
	}
}

void 	push_up_b(t_ledger *root, t_stack *stk, t_node *node)
{
	size_t	index;

	index = get_index(stk, node);
	//printf("index: %lu\n", index);
	while (index != 0)
	{
		if (index <= root->bsize / 2)
		{
			put_instruction(root, 6);
			index--;
		}
		else if (index > root->bsize / 2)
		{
			put_instruction(root, 9);
			index++;
			if (index == root->bsize)
				index = 0;
		}
	}
}

void	insert_b(t_ledger *ledger, int index)
{
	t_node	*tmp;
	int		pivot;
	int		om;

	tmp = get_nth(ledger->a, index);
	pivot = find_pivot(ledger->b, tmp->data);
	//printf("index: %d pivot: %d", index, pivot);
	om = optimal_move(ledger, index, pivot);
	//printf("Final Strat: %d\n", om);
	if (om == 0)
	{
		strat_one(ledger, index, pivot);
	}
	else if (om == 1)
	{
		strat_two(ledger, index, pivot);
	}
	else if (om == 2)
	{
		strat_three(ledger, index, pivot);
	}
}

void 	strat_one(t_ledger *ledger, int index, int pivot)
{
	size_t	i;
	size_t	p;

	i = index;
	p = pivot;
	if (i <= ledger->asize / 2)
	{
		while (i > 0)
		{
			put_instruction(ledger, 5);
			i--;
		}
	}
	else if (i > ledger->asize / 2)
	{
		while (i != 0)
		{
			put_instruction(ledger, 8);
			i++;
			if (i == ledger->asize)
				i = 0;
		}
	}
	if (p <= ledger->bsize / 2)
	{
		while (p > 0)
		{
			put_instruction(ledger, 6);
			p--;
		}
	}
	else if (p > ledger->bsize / 2)
	{
		while (p != 0)
		{
			put_instruction(ledger, 9);
			p++;
			if (p == ledger->bsize)
				p = 0;
		}
	}
	if (i == 0 && p == 0)
		put_instruction(ledger, 4);
}

void 	strat_two(t_ledger *ledger, int index, int pivot)
{
	size_t	p;
	size_t	i;

	p = pivot;
	i = index;
	if (i > p)
	{
		while (i > p)
		{
			put_instruction(ledger, 5);
			i--;
		}
		while (i > 0)
		{
			put_instruction(ledger, 7);
			i--;
		}
	}
	else if (p > i)
	{
		while (p > i)
		{
			put_instruction(ledger, 6);
			p--;
		}
		while (p > 0)
		{
			put_instruction(ledger, 7);
			p--;
		}
	}
	else
	{
		while (p > 0)
		{
			put_instruction(ledger, 7);
			p--;
		}
	}
	put_instruction(ledger, 4);
}

void 	strat_three(t_ledger *ledger, int index, int pivot)
{
	size_t	p;
	size_t	i;

	p = pivot;
	i = index;
	if ((ledger->bsize - p) > (ledger->asize - i))
	{
		while ((ledger->bsize - p) > (ledger->asize - i))
		{
			put_instruction(ledger, 9);
			p++;
		}
		while (ledger->bsize > p)
		{
			put_instruction(ledger, 10);
			p++;
		}
	}
	else if ((ledger->bsize - p) < (ledger->asize - i))
	{
		while ((ledger->bsize - p) < (ledger->asize - i))
		{
			put_instruction(ledger, 8);
			i++;
		}
		while (ledger->asize > i)
		{
			put_instruction(ledger, 10);
			i++;
		}
	}
	else
	{
		while (p < ledger->bsize)
		{
			put_instruction(ledger, 10);
			p++;
		}
	}
	put_instruction(ledger, 4);
}

void 	put_instruction(t_ledger *root, int i)
{
	printf("%s\n", root->instructions[i]);
	g_stack[i](root);
	root->i_count++;
}

int		get_insert(t_ledger *root)
{
	int index;
	int lmoves;
	int tmoves;
	size_t i;

	i = 0;
	lmoves = calculate_score(root, i++);
	index = 0;
	while (i <= root->asize / 2)
	{
		tmoves = calculate_score(root, i);
		if (tmoves < lmoves)
		{
			index = i;
			lmoves = tmoves;
		}
		tmoves = calculate_score(root, root->asize - i);
		if (tmoves < lmoves)
		{
			index = root->asize - i;
			lmoves = tmoves;
		}
		i++;
	}
	return (index);
}
