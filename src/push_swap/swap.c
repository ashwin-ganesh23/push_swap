#include "push_swap.h"

void		sa(t_ledger *stk)
{
	t_node	*tmp;
	t_node	*temp;

	if (stk->asize > 1)
	{
		temp = stk->a->head;
		tmp = temp->next->next;
		tmp->prev = temp;
		stk->a->head = temp->next;
		stk->a->head->next = temp;

		stk->a[stk->asize - 1] = stk->a[stk->asize - 2];
		stk->a[stk->asize - 2] = tmp;
	}
}

void		sb(t_ledger *stk)
{
	int 	tmp;

	if (stk->bsize > 1)
	{
		tmp = stk->b[stk->bsize - 1];
		stk->b[stk->bsize - 1] = stk->b[stk->bsize - 2];
		stk->b[stk->bsize - 2] = tmp;
	}
}

void		ss(t_ledger *stk)
{
	sa(stk);
	sb(stk);
}
