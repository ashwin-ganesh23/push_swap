#include "push_swap.h"

void		rra(t_ledger *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->asize > 1)
	{
		tsize = 0;
		tmp = stk->a[0];
		while (tsize < stk->asize)
		{
			stk->a[tsize] = stk->a[tsize + 1];
			tsize++;
		}
		stk->a[stk->asize] = tmp;
	}
}

void		rrb(t_ledger *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->bsize > 1)
	{
		tsize = 0;
		tmp = stk->b[0];
		while (tsize < stk->bsize)
		{
			stk->b[tsize] = stk->b[tsize + 1];
			tsize++;
		}
		stk->b[stk->bsize] = tmp;
	}
}

void		rrr(t_ledger *stk)
{
	rra(stk);
	rrb(stk);
}
