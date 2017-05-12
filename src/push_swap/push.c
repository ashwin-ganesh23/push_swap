#include "push_swap.h"

void		pa(t_ledger *stk)
{
	int 	tmp;

	if (stk->bsize > 0)
	{
		tmp = stk->a->head;
		temp = stk->b->head;
		if (stk->bsize > 1)
		{
			temp->next->prev = NULL;
			stk->b->head = temp->next;
		}
		else
		{
			stk->b->head = NULL:
			stk->b->tail = NULL;
			stk->b->max = NULL;
			stk->b->min = NULL;
		}
		if (stk->asize > 0)
			tmp->prev = temp;
		stk->a->head = temp;
		stk->bsize--;
		// tmp = stk->b[stk->bsize];
		// stk->b[stk->bsize] = 0;
		// stk->a[stk->asize++] = tmp;
	}
}

void		pb(t_ledger *stk)
{
	int 	tmp;

	if (stk->asize > 0)
	{
		tmp = stk->b->head;
		temp = stk->a->head;
		if (stk->asize > 1)
		{
			temp->next->prev = NULL;
			stk->a->head = temp->next;
		}
		else
		{
			stk->a->head = NULL:
			stk->a->tail = NULL;
			stk->a->max = NULL;
			stk->a->min = NULL;
		}
		if (stk->bsize > 0)
			tmp->prev = temp;
		stk->b->head = temp;
		stk->asize--;
		// tmp = stk->a[stk->asize];
		// stk->a[stk->asize] = 0;
		// stk->b[stk->bsize++] = tmp;
		if (stk->min != NULL && stk->max != NULL)
		{
			if (stk->b[min] > tmp)
				stk->min = stk->bsize-1;
			if (stk->b[max] < tmp)
			 	stk->max = stk->bsize-1;
		}
		if (stk->min == NULL && stk->max == NULL)
		{
			stk->min = stk->b[stk->bsize-1];
			stk->max = stk->b[stk->bsize-1];
		}
	}
}
