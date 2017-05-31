#include "../includes/checker.h"

void		rra(t_stack *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->asize > 1)
	{
		tsize = 0;
		tmp = stk->a[0];
		while (tsize < stk->asize - 1)
		{
			stk->a[tsize] = stk->a[tsize + 1];
			tsize++;
		}
		stk->a[stk->asize - 1] = tmp;
	}
}

void		rrb(t_stack *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->bsize > 1)
	{
		tsize = 0;
		tmp = stk->b[0];
		while (tsize < stk->bsize - 1)
		{
			stk->b[tsize] = stk->b[tsize + 1];
			tsize++;
		}
		stk->b[stk->bsize - 1] = tmp;
	}
}

void		rrr(t_stack *stk)
{
	rra(stk);
	rrb(stk);
}
