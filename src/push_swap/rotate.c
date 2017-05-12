#include "push_swap.h"

void		ra(t_ledger *stk)
{
	if (stk->asize > 1)
	{
		stk->a->tail = stk->a->head;
		stk->a->head = stk->a->head->next;
	}
}

void		rb(t_ledger *stk)
{
	if (stk->bsize > 1)
	{
		stk->b->tail = stk->b->head;
		stk->b->head = stk->a->head->next;
	}
}

void		rr(t_ledger *stk)
{
	ra(stk);
	rb(stk);
}
