#include "../includes/checker.h"

void		sa(t_stack *stk)
{
	int 	tmp;

	if (stk->asize > 1)
	{
		tmp = stk->a[stk->asize - 1];
		stk->a[stk->asize - 1] = stk->a[stk->asize - 2];
		stk->a[stk->asize - 2] = tmp;
	}
}

void		sb(t_stack *stk)
{
	int 	tmp;

	if (stk->bsize > 1)
	{
		tmp = stk->b[stk->bsize - 1];
		stk->b[stk->bsize - 1] = stk->b[stk->bsize - 2];
		stk->b[stk->bsize - 2] = tmp;
	}
}

void		ss(t_stack *stk)
{
	sa(stk);
	sb(stk);
}
