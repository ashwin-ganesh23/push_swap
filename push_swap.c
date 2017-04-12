#include "push_swap.h"

int 	check_duplicates(t_ledger *root, int n)
{
	int 	i;

	i = 0;
	while (root->a[i] != 0)
	{
		if (root->a[i++] == n)
			return (0);
	}
	return (1);
}

void    parse_pargs(t_ledger *root, int argc, char **argv)
{
	int 	i;

	i = 0;
	while (argc > 1)
	{
		if (!valid_int(argv[--argc]))
			put_error();
		if (!check_duplicates(root, ft_atoi(argv[argc])))
			put_error();
		root->a[i++] = ft_atoi(argv[argc]);
	}
	root->a[i] = '\0';
}

void 	calculate_scores(t_stack *ledger)
{
	size_t 	size;
	int 	min;

	size = ledger->asize;
	min = 0;
	while (size > 0)
	{
		ledger->ascores[--size] =
	}
}

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
    if (ft_strcmp(first->sd->d_name, second->sd->d_name) < 0)
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

void 	set_place(t_stack *ledger)
{
	int 	real[ledger->asize];
	int 	i;

	i = 0;
	//sort
	while (i < ledger->asize)
	{
		//store true positions
	}
	real[]
}

int 	initialize_ledger(t_stack *ledger, int argc)
{
	int 	i;

	i = 0;
	if ((root->a = (int *)malloc(sizeof(int) * argc)) == NULL)
		return (0);
	if ((root->b = (int *)malloc(sizeof(int) * argc)) == NULL)
		return (0);
	if ((root->ascores = (int *)malloc(sizeof(int) * argc)) == NULL)
		return (0);
	if ((root->instructions = (char**)malloc(sizeof(char*) * 11)) == NULL)
		return (0);
	while (i < 11)
	{
		if ((root->instructions[i++] = (char *)malloc(sizeof(char) * 4)) == NULL)
			return (0);
	}
	root->asize = argc - 1;
	root->bsize = 0;
	root->instructions[0] = "sa\0";
	root->instructions[1] = "sb\0";
	root->instructions[2] = "ss\0";
	root->instructions[3] = "pa\0";
	root->instructions[4] = "pb\0";
	root->instructions[5] = "ra\0";
	root->instructions[6] = "rb\0";
	root->instructions[7] = "rr\0";
	root->instructions[8] = "rra";
	root->instructions[9] = "rrb";
	root->instructions[10] = "rrr";
	return (1);
}

int		main(int argc, char **argv)
{
	t_ledger root;

	if (argc < 2)
		exit(0);
	if (!initialize_ledger(&root, argc))
		return (0);
	parse_pargs(&root, argc, argv);
	set_place(&root);
	calculate_scores(&root);
}
