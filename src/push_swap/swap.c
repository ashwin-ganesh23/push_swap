#include "push_swap.h"

void		sa(t_ledger *stk)
{
	t_node	*tmp;
	t_node	*temp;

	if (stk->asize > 1)
	{
		if (stk->asize == 2)
		{
			tmp = stk->a->head;
			temp = stk->a->tail;
			stk->a->head = temp;
			stk->a->tail = tmp;
			stk->a->head->next = stk->a->tail;
			stk->a->head->prev = stl->a->tail;
			stk->a->tail->next = stl->a->head;
			stk->a->tail->prev = stl->a->head;
		}
		else
		{
			temp = stk->a->head;
			tmp = temp->next->next;
			tmp->prev = temp;
			stk->a->head = temp->next;
			temp->next = tmp;
			temp->prev = stk->a->head;
			stk->a->head->next = temp;
			stk->a->tail->next = stk->a->head;
			stk->a->head->prev = stk->a->tail;
		}
	}
}

void		sb(t_ledger *stk)
{
	t_node	*tmp;
	t_node	*temp;

	if (stk->bsize > 1)
	{
		if (stk->bsize == 2)
		{
			tmp = stk->b->head;
			temp = stk->b->tail;
			stk->b->head = temp;
			stk->b->tail = tmp;
			stk->b->head->next = stk->b->tail;
			stk->b->head->prev = stl->b->tail;
			stk->b->tail->next = stl->b->head;
			stk->b->tail->prev = stl->b->head;
		}
		else
		{
			temp = stk->b->head;
			tmp = temp->next->next;
			tmp->prev = temp;
			stk->b->head = temp->next;
			temp->next = tmp;
			temp->prev = stk->b->head;
			stk->a->head->next = temp;
			stk->a->tail->next = stk->a->head;
			stk->a->head->prev = stk->a->tail;
		}
	}
}

void		ss(t_ledger *stk)
{
	sa(stk);
	sb(stk);
}
