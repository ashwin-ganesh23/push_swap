#include "../includes/push_swap.h"

t_node	*new_nodelst(int input)
{
	t_node 	*node;

	if ((node = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (0);
	node->next = NULL;
	node->prev = NULL;
	node->data = input;
	return (node);
}

int		insert_node(t_node *head, t_stack *master, int input)
{
	t_node *temp;

	if ((temp = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (0);
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = input;
	if (!head)
		head = temp;
	else
	{
		temp->next = head;
		head->prev = temp;
		master->head = temp;
	}
	temp->next = head;
	master->head = temp;
	return (0);
}

t_node	*get_nth(t_stack *stack, int i)
{
	t_node	*tmp;
	int		index;

	index = i;
	tmp = stack->head;
	while (index > 0)
	{
		tmp = tmp->next;
		index--;
	}
	while (index < 0)
	{
		tmp = tmp->prev;
		index++;
	}
	return (tmp);
}

int		get_dindex(t_stack *stack, int d, size_t size)
{
	t_node	*tmp;
	size_t	index;

	index = 0;
	tmp = stack->head;
	while (index < size)
	{
		if (tmp->data == d)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int		get_index(t_stack *stack, t_node *input)
{
	t_node	*thead;
	int		index;

	thead = stack->head;
	index = 0;
	while (thead->data != input->data)
	{
		thead = thead->next;
		index++;
	}
	return (index);
}
