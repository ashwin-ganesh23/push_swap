#include "push_swap.h"

void		rra(t_ledger *stk)
{
	if (stk->asize > 1)
	{
		stk->a->head = stk->a->tail;
		stk->a->tail = stk->a->tail->prev;
	}
}

void		rrb(t_ledger *stk)
{
	if (stk->bsize > 1)
	{
		stk->b->head = stk->b->tail;
		stk->b->tail = stk->b->tail->prev;
	}
}

void		rrr(t_ledger *stk)
{
	rra(stk);
	rrb(stk);
}
