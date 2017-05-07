#include "push_swap.h"

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

int		insert_node(t_node *head, t_list *master, int input)
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
	temp->next = node;
	node = temp;
	return (0);
}
