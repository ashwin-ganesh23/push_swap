#include "../includes/push_swap.h"

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
	t_node 	*ap;
	t_node	*bp;
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

void 	small_solver()
{

}
