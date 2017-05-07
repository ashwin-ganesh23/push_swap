#include "push_swap.h"

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
