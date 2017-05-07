#include "push_swap.h"

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
