#include "../includes/push_swap.h"

int 	small_solver(t_ledger *ledger)
{
	if (ledger->asize == 1)
		return (0);
	while (ledger->asize > 3)
	{
		push_twomin(ledger);
	}
	//print_stacks(ledger);
	sort_in_place(ledger);
	while (ledger->bsize > 0)
		put_instruction(ledger, 3);
    return (0);
}

void 	sort_in_place(t_ledger *ledger)
{
	t_node	*tmp;
	// int		count;
	// int		min;
	// int		low;

	set_maxmin(ledger);
	if (ledger->asize == 2)
	{
		if (ledger->a->head->data > ledger->a->tail->data)
			put_instruction(ledger, 0);
	}
	else if (ledger->asize == 3)
	{
		tmp = ledger->a->max3;
		if (tmp->next != ledger->a->max2)
			put_instruction(ledger, 0);
		if (ledger->a->tail == tmp)
			put_instruction(ledger, 8);
		else if (ledger->a->head != tmp)
			put_instruction(ledger, 5);
	}

	// count = 0;
	// min = 0;
	// low = tmp->data;
	// tmp = tmp->next;
	// if (!solved(ledger))
	// {
	// 	while (count < 2)
	// 	{
	// 		if (tmp->data < low)
	// 		{
	// 			low = tmp->data;
	// 			min = count;
	// 		}
	// 		count++;
	// 		tmp = tmp->next;
	// 	}
	// 	tmp = get_nth(ledger->a, min);
	// 	if (tmp->next->data > tmp->prev->data)
	// 		put_instruction(ledger, 0);
	// 	count = get_index(ledger->a, tmp);
	// 	//printf("count: %d\n", count);
	// 	if (count == 2)
	// 	{
	// 		put_instruction(ledger, 8);
	// 	}
	// 	else if (count == 1)
	// 		put_instruction(ledger, 5);
	// }
}

void	insert_sb(t_ledger *ledger, int index)
{
	int		pivot;

	pivot = 0;
	strat_one(ledger, index, pivot);
}

void 	push_twomin(t_ledger *root)
{
	int		min;
	int		mini;
	size_t	size;
	t_node	*tmp;

	tmp = root->a->head;
	if (tmp->data < tmp->next->data)
	{
		min = tmp->data;
		mini = tmp->next->data;
	}
	else
	{
		min = tmp->next->data;
		mini = tmp->data;
	}
	size = 2;
	tmp = tmp->next;
	while (size < root->asize)
	{
		tmp = tmp->next;
		if (tmp->data < min)
		{
			mini = min;
			min = tmp->data;
		}
		else if (tmp->data < mini)
			mini = tmp->data;
		size++;
	}
	if (get_dindex(root->a, mini, root->asize) == 0)
	{
		mini = get_dindex(root->a, mini, root->asize);
		insert_sb(root, mini);
		min = get_dindex(root->a, min, root->asize);
		insert_sb(root, min);
	}
	else
	{
		min = get_dindex(root->a, min, root->asize);
		insert_sb(root, min);
		mini = get_dindex(root->a, mini, root->asize);
		insert_sb(root, mini);
	}
}
