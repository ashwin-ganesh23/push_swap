#include "../includes/push_swap.h"

void		pa(t_ledger *stk)
{
	t_node 	*tmp;
	t_node	*temp;

	if (stk->bsize > 0)
	{
		tmp = stk->a->head;
		temp = stk->b->head;
		if (stk->bsize > 1)
		{
			temp->next->prev = NULL;
			stk->b->head = temp->next;
			stk->b->tail->next = stk->b->head;
		}
		else
		{
			stk->b->head = NULL:
			stk->b->tail = NULL;
			stk->b->max = NULL;
			stk->b->min = NULL;
		}
		if (stk->asize == 0)
		{
			stk->a->head = temp;
			stk->a->tail = temp;
		}
		else
		{
			tmp->prev = temp;
			temp->next = tmp;
			temp->prev = stk->a->tail;
			stk->a->head = temp;
			stk->a->tail->next = stk->a->head;
		}
		stk->bsize--;
		stk->asize++;
	}
}

void		pb(t_ledger *stk)
{
	t_node	*tmp;
	t_node	*temp;

	if (stk->asize > 0)
	{
		tmp = stk->b->head;
		temp = stk->a->head;
		if (stk->asize > 1)
		{
			temp->next->prev = NULL;
			stk->a->head = temp->next;
			stk->a->tail->next = stk->a->head;
		}
		else
		{
			stk->a->head = NULL:
			stk->a->tail = NULL;
		}
		if (stk->bsize == 0)
		{
			stk->b->head = temp;
			stk->b->tail = stk->b->head;
		}
		else
		{
			tmp->prev = temp;
			temp->next = tmp;
			temp->prev = stk->b->tail;
			stk->b->head = temp;
			stk->b->tail->next = stk->b->head;
		}
		stk->asize--;
		stk->bsize++;
		if (stk->min != NULL && stk->max != NULL)
		{
			if (stk->b->min->data > tmp->data)
				stk->min = tmp;
			if (stk->b->max->data < tmp->data)
			 	stk->max = tmp;
		}
		if (stk->min == NULL && stk->max == NULL)
		{
			stk->min = tmp;
			stk->max = tmp;
		}
	}
}


// tmp = stk->b[stk->bsize];
// stk->b[stk->bsize] = 0;
// stk->a[stk->asize++] = tmp;
