#include "../includes/push_swap.h"

void 	big_solver(t_ledger *root)
{
	int index;

	while (root->bsize < 2)
		put_instruction(root, 4);
	while (root->asize > 0)
	{
		index = get_insert(root);
		insert_b(root, index);
	}
	index = get_index(root->b, root->b->max);
	while (index != 0)
	{
		if (index < root->bsize / 2)
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
	while (root->bsize != 0)
		put_instruction(root, 4);
}

void	insert_b(t_ledger *ledger, int index)
{
	t_node	*tmp;
	int		pivot;
	int		om;

	tmp = get_nth(ledger->a, index);
	pivot = find_pivot(ledger->b, tmp->data);
	om = optimal_move(ledger, index, pivot);
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
	int		i;
	int		p;

	i = index;
	p = pivot;
	if (i < ledger->asize / 2)
	{
		while (i > 0)
		{
			put_instruction(root, 5);
			i--;
		}
	}
	else if (i > ledger->asize / 2)
	{
		while (i != 0)
		{
			put_instruction(root, 8);
			i++:
		}
		if (i == ledger->bsize)
			i == 0;
	}
	if (p < ledger->bsize / 2)
	{
		while (p > 0)
		{
			put_instruction(root, 6);
			p--;
		}
	}
	else if (p > ledger->asize / 2)
	{
		while (p != 0)
		{
			put_instruction(root, 9);
			p++:
		}
		if (p == ledger->bsize)
			p == 0;
	}
	if (i == 0 && p == 0)
		put_instruction(root, 4);
}

void 	strat_two(t_ledger *ledger, int index, int pivot)
{
	int		diff;
	int		p;
	int		i;

	p = pivot;
	i = index;
	if (i > p)
	{
		diff = i - p;
		while (p > 0)
		{
			put_instruction(root, 7);
			p--;
		}
		while (diff > 0)
		{
			put_instruction(root, 5);
			diff--;
		}
	}
	else if (p > i)
	{
		diff = p - i;
		while (i > 0)
		{
			put_instruction(root, 7);
			i--
		}
		while (diff > 0)
		{
			put_instruction(root, 6);
			diff--;
		}
	}
	else
	{
		while (p > 0)
		{
			put_instruction(root, 7);
			p--;
		}
	}
	put_instruction(root, 4);
}

void 	strat_three(t_ledger *ledger, int index, int pivot)
{
	int		diff;
	int		p;
	int		i;

	p = pivot;
	i = index;
	if ((ledger->bsize - p) > (ledger->asize - i))
	{
		diff = (ledger->bsize - p) - (ledger->asize - i);
		while (i < ledger->bsize)
		{
			put_instruction(root, 10);
			i++;
		}
		while (diff > 0)
		{
			put_instruction(root, 9);
			diff--;
		}
	}
	else if ((ledger->bsize - p) < (ledger->asize - i))
	{
		diff = (ledger->asize - i) - (ledger->bsize - p);
		while (p < ledger->asize)
		{
			put_instruction(root, 10);
			p++;
		}
		while (diff > 0)
		{
			put_instruction(root, 8);
			diff--;
		}
	}
	else
	{
		while (p > ledger->bsize)
		{
			put_instruction(root, 10);
			p--;
		}
	}
	put_instruction(root, 4);
}

void 	put_instruction(t_ledger *root, int i)
{
	printf("%s\n", root->instructions[i]);
	g_funcs[i](root);
}

int		get_insert(t_ledger *root)
{
	int index;
	int lmoves;
	int tmoves;
	int i;

	i = 0;
	lmoves = calculate_score(root, i++);
	index = 0;
	while (i < root->asize / 2)
	{
		tmoves = calculate_score(root, i);
		if (tmoves < lmoves)
			index = i;
		i *= -1;
		tmoves = calculate_score(root, i);
		if (tmoves < lmoves)
			index = i;
		i *= -1;
		i++;
	}
	return (lowest);

	calculate_score(root);
	index = pick_score(root);
}
