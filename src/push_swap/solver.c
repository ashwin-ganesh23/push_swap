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
	// if (tmp == ledger->a->max || tmp == ledger->a->max2 ||
	// 	 tmp == ledger->a->max3)
	// 	 return (250);
	return (optimal_score(ledger, i, pivot));
}

int		optimal_score(t_ledger *ledger, int i, int pivot)
{
	size_t	optimal;
	size_t	rrr;
	size_t	rr;

	optimal = ((size_t)i <= (ledger->asize / 2)) ? (size_t)i : ledger->asize - i;
	optimal += ((size_t)pivot <= (ledger->bsize / 2)) ? (size_t)pivot : ledger->bsize - pivot;
	if (ledger->asize - i < ledger->bsize - pivot)
		rrr = ledger->bsize - pivot;
	else
		rrr = ledger->asize - i;
	rr = (i > pivot) ? i : pivot;
	if (rr < optimal && rr <= rrr)
		optimal = rr;
	else if (rrr < optimal && rrr <= rr)
		optimal = rrr;
	return (optimal);
}

int		optimal_move(t_ledger *ledger, int i, int pivot)
{
	size_t	optimal;
	size_t	rrr;
	size_t	rr;
	size_t	ret;

	optimal = 0;
	rrr = 0;
	rr = 0;
	ret = 0;
	optimal = ((size_t)i <= (ledger->asize / 2)) ? (size_t)i : ledger->asize - i;
	optimal += ((size_t)pivot <= (ledger->bsize / 2)) ? (size_t)pivot : ledger->bsize - pivot;
	if (ledger->asize - i < ledger->bsize - pivot)
		rrr = ledger->bsize - pivot;
	else
		rrr = ledger->asize - i;
	rr = (i > pivot) ? i : pivot;
	if (rr <= optimal && rr <= rrr)
		ret = 1;
	else if (rrr <= optimal && rrr <= rr)
		ret = 2;
	return (ret);
}



int		find_pivot(t_stack *sb, int data)
{
	t_node	*tmp;

	tmp = sb->min;
	if (data > sb->max->data)
		return (get_index(sb, sb->max));
	else if (data < sb->min->data)
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
