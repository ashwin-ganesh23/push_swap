#include "../includes/checker.h"

void		ra(t_stack *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->asize > 1)
	{
		tsize = stk->asize - 1;
		tmp = stk->a[tsize];
		while (tsize >= 1)
		{
			stk->a[tsize] = stk->a[tsize - 1];
			tsize--;
		}
		stk->a[0] = tmp;
	}
}

void		rb(t_stack *stk)
{
	size_t 	tsize;
	int 	tmp;

	if (stk->bsize > 1)
	{
		tsize = stk->bsize - 1;
		tmp = stk->b[tsize];
		while (tsize >= 1)
		{
			stk->b[tsize] = stk->b[tsize - 1];
			tsize--;
		}
		stk->b[0] = tmp;
	}
}

void		rr(t_stack *stk)
{
	ra(stk);
	rb(stk);
}
