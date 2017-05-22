#include "../includes/push_swap.h"

void 	solver(t_ledger *root)
{
	if (root->asize <= 5)
	{
		small_solver(root);
	}
	else
	{
		big_solver(root);
	}
}

int		calculate_score(t_ledger *ledger, int i)
{
	t_node	*tmp;
	int		pivot;

	tmp = get_nth(ledger->a, i);
	//printf("%d\n", tmp->data);
	pivot = find_pivot(ledger->b, tmp->data);
	//printf("pivot: %d\n", pivot);
	return (optimal_score(ledger, i, pivot));
}

int		optimal_score(t_ledger *ledger, int i, int pivot)
{
	size_t	optimal;
	size_t	rrr;
	size_t	rr;
	size_t	index;

	index = i;
	optimal = (index <= (ledger->asize / 2)) ? (size_t)i : ledger->asize - i;
	optimal += (index <= (ledger->bsize / 2)) ? (size_t)i : ledger->bsize - i;
	rrr = (i < pivot) ? ledger->bsize - pivot : ledger->asize - i;
	rrr += (rrr == ledger->bsize - pivot) ? pivot - i : i - pivot;
	rr = (i > pivot) ? pivot : i;
	rr += (rr == (size_t)pivot) ? i - pivot : pivot - i;
	if (rr < optimal)
		optimal = rr;
	if (rrr < optimal)
		optimal = rrr;
	return (optimal);
}

int		optimal_move(t_ledger *ledger, int i, int pivot)
{
	size_t	optimal;
	size_t	rrr;
	size_t	rr;
	size_t	ret;
	size_t	index;

	index = i;
	optimal = (index <= ledger->asize / 2) ? (size_t)i : ledger->asize - i;
	optimal += (index <= ledger->bsize / 2) ? (size_t)i : ledger->bsize - i;
	rrr = (i < pivot) ? ledger->bsize - pivot : ledger->asize - i;
	rrr += (rrr == ledger->bsize - pivot) ? pivot - i : i - pivot;
	rr = (i > pivot) ? pivot : i;
	rr += (rrr == (size_t)pivot) ? i - pivot : pivot - i;
	if (rr < optimal)
		ret = 1;
	else if (rrr < optimal)
		ret = 2;
	else
		ret = 0;
	return (ret);
}



int		find_pivot(t_stack *sb, int data)
{
	t_node	*tmp;

	tmp = sb->min;
	if (data > sb->max->data)
		return (get_index(sb, sb->max));
	if (data < sb->min->data)
		return (get_index(sb, sb->max));
	//printf("%i\n", tmp->data);
	tmp = tmp->prev;
	//printf("%i\n", tmp->data);
	while (tmp->data != sb->min->data)
	{
		if (data < tmp->data)
			return (get_index(sb, tmp->next));
		tmp = tmp->prev;
	}
	return (get_index(sb, tmp));
}

// int		calculate_score(t_stack *ledger, int i)
// {
// 	t_node 	*ap;
// 	t_node	*bp;
// 	int 	min;
//
// 	min = 0;
// 	stacka = ledger->a->head;
// 	stackb = ledger->b->head;
// 	tailb = ledger->b->tail;
// 	if (bsize <= 2)
// 		return (0);
// 	else
// 	{
// 		min = 0;
// 		if ((stacka->pos < stackb->pos && stacka->pos > tailb->pos) ||
// 		 (stacka->pos > stackb->pos && stacka->pos < tailb->pos))
// 		 	return (min);
// 		if (stacka->pos > stackb->pos)
// 		{
// 			while (stacka->pos > stackb->pos)
// 			{
// 				stackb = stackb->next;
// 				min++;
// 			}
// 		}
// 		while (stacka->pos > stackb->pos)
// 		{
// 			stackb = stackb->next;
// 			min++;
// 		}
// 		i = (i > (ledger->asize / 2)) ? i: ledger->asize - i;
// 		min = (min > (ledger->bsize / 2) ? i : 0,ledger->asize - i);
// 		stacka->score = min + i;
// 	}
// 	i++;
// }

// int 	pick_score(t_stack *ledger)
// {
// 	int 	i;
// 	int		min;
// 	int		imin;
// 	t_node 	tmp;
//
// 	i = 0;
// 	imin = 0;
// 	min = 1000;
// 	tmp = ledger->a->head;
// 	while (i < ledger->asize)
// 	{
// 		if (tmp->score < min)
// 		{
// 			min = tmp->score;
// 			imin = i;
// 		}
// 		i++;
// 	}
// 	return (imin);
// }
