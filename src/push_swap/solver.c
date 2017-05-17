#include "push_swap.h"

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
	}
}

int		calculate_score(t_stack *ledger, int i)
{
	t_node	*tmp;
	int		pivot;

	tmp = get_nth(ledger->a, i);
	pivot = find_pivot(ledger->b, tmp->data);
	return (optimal_score(ledger, i, pivot));
}

t_node	*get_nth(t_list *stack, int i)
{
	t_node	*tmp;
	int		index;

	index = i;
	tmp = stack->head;
	while (index > 0)
	{
		tmp = tmp->next;
		index--;
	}
	while (index < 0)
	{
		tmp = tmp->prev;
		index++;
	}
	return (tmp);
}

int		optimal_score(t_stack *ledger, int i, int pivot)
{
	int		optimal;
	int		rrr;
	int		rr;

	optimal = (i < ledger->asize / 2) ? i : ledger->asize - i;
	optimal += (i < ledger->bsize / 2) ? i : ledger->bsize - i;
	rrr = (i < pivot) ? ledger->bsize - pivot : ledger->asize - i;
	rrr += (rrr == ledger->bsize - pivot) ? pivot - i : i - pivot;
	rr = (i > pivot) ? pivot : i;
	rr += (rrr == pivot) ? i - pivot : pivot - i;
	if (rr < optimal)
		optimal = rr;
	if (rrr < optimal)
		optimal = rrr;
	return (optimal);
}

int		optimal_move(t_stack *ledger, int i, int pivot)
{
	int		optimal;
	int		rrr;
	int		rr;
	int		ret;

	optimal = (i < ledger->asize / 2) ? i : ledger->asize - i;
	optimal += (i < ledger->bsize / 2) ? i : ledger->bsize - i;
	rrr = (i < pivot) ? ledger->bsize - pivot : ledger->asize - i;
	rrr += (rrr == ledger->bsize - pivot) ? pivot - i : i - pivot;
	rr = (i > pivot) ? pivot : i;
	rr += (rrr == pivot) ? i - pivot : pivot - i;
	if (rr < optimal)
		ret = 1;
	else if (rrr < optimal)
		ret = 2;
	else
		ret = 0;
	return (ret);
}



int		find_pivot(t_list *sb, int data)
{
	t_node	tmp;

	tmp = sb->b->min;
	if (data > sb->max->data)
		return (get_index(sb, sb->max));
	if (data < sb->min->data)
		return (get_index(sb, sb->min));
	while (tmp->data != sb->max data)
	{
		if (data < tmp->data)
			return (get_index(sb, tmp));
		tmp = tmp->next;
	}

}

int		get_index(t_list *stack, t_node input)
{
	t_node	thead;
	int		index;

	thead = stack->head;
	while (thead->data != input->data)
	{
		thead = thead->next;
		index++;
	}
	return (index);
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
