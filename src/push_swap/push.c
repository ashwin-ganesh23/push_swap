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
			temp->next->prev = stk->a->tail;
			stk->b->head = temp->next;
			stk->b->tail->next = stk->b->head;
			if (temp->data == stk->b->max->data)
				stk->b->max = stk->b->max->prev;
			if (temp->data == stk->b->min->data)
				stk->b->min = stk->b->min->next;
		}
		else
		{
			stk->b->head = NULL;
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
			temp->next->prev = stk->a->tail;
			stk->a->head = temp->next;
			stk->a->tail->next = stk->a->head;
		}
		else
		{
			stk->a->head = NULL;
			stk->a->tail = NULL;
		}
		if (stk->bsize == 0)
		{
			stk->b->tail = temp;
			stk->b->head = stk->b->tail;
			stk->b->head->next = stk->b->tail;
			stk->b->tail->next = stk->b->head;
			stk->b->head->prev = stk->b->tail;
			stk->b->tail->prev = stk->b->head;
		}
		else
		{
			stk->b->head->prev = temp;
			stk->b->tail->next = temp;
			temp->next = stk->b->head;
			temp->prev = stk->b->tail;
			stk->b->head = temp;
		}
		stk->asize--;
		stk->bsize++;
		if (stk->b->min != NULL && stk->b->max != NULL)
		{
			if (stk->b->min->data > temp->data)
				stk->b->min = temp;
			if (stk->b->max->data < temp->data)
			 	stk->b->max = temp;
		}
		else
		{
			stk->b->min = temp;
			stk->b->max = temp;
		}
	}
}


// tmp = stk->b[stk->bsize];
// stk->b[stk->bsize] = 0;
// stk->a[stk->asize++] = tmp;
