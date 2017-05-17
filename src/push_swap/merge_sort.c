#include "../includes/push_swap.h"

t_node	*split(t_node *head)
{
    t_node	*fast;
	t_node	*slow;
	t_node	*temp;

	fast = head;
	slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    temp = slow->next;
    slow->next = NULL;
    return (temp);
}

t_node	*merge(t_node *first, t_node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    if (first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

t_node	*merge_sort(t_node *head)
{
	t_node	*second;

	if (!head || !head->next)
        return (head);
    second = split(head);
    head = merge_sort(head);
    second = merge_sort(second);
    return (merge(head,second));
}
