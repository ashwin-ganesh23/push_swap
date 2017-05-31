#include "../includes/checker.h"

void		pa(t_stack *stk)
{
	int 	tmp;

	if (stk->bsize > 0)
	{
		stk->bsize--;
		tmp = stk->b[stk->bsize];
		stk->b[stk->bsize] = '\0';
		stk->a[stk->asize] = tmp;
		stk->asize++;
		stk->a[stk->asize] = '\0';
	}
}

void		pb(t_stack *stk)
{
	int 	tmp;

	if (stk->asize > 0)
	{
		stk->asize--;
		tmp = stk->a[stk->asize];
		stk->a[stk->asize] = '\0';
		stk->b[stk->bsize] = tmp;
		stk->bsize++;
		stk->b[stk->bsize] = '\0';
	}
}
