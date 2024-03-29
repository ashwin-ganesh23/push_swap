#include "../includes/push_swap.h"

void	put_error()
{
	ft_putstr("Error\n");
	exit (0);
}

void 	(*g_stack[11])(t_ledger *stk) =
{
	&sa,
	&sb,
	&ss,
	&pa,
	&pb,
	&ra,
	&rb,
	&rr,
	&rra,
	&rrb,
	&rrr,
};

int		solved(t_ledger *root)
{
	int		count;
	int		value;
	t_node	*tmp;

	count = root->asize - 1;
	tmp = root->a->head;
	while (count > 0)
	{
		value = tmp->data;
		tmp = tmp->next;
		if (value > tmp->data)
			return (0);
		count--;
	}
	return (1);
}

int		ordered(t_ledger *root)
{
	t_node	*tmp;

	if (root->asize > 1)
	{
		set_maxmin(root);
		tmp = root->a->min;
		while (tmp->next->data != root->a->min->data)
		{
			if (tmp->data > tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_ledger 	root;
	// t_node		*tmp;
	// size_t i = 0;

	if (argc < 2)
		return (0);
	//printf("test\n");
	if (!initialize_ledger(&root))
		return (0);
	//printf("test\n");
	parse_pargs(&root, argc, argv);
	// tmp = root.a->head;
	// while (i < root.asize)
	// {
	// 	printf("%d\n", tmp->data);
	// 	tmp = tmp->next;
	// 	i++;
	// }
	//set_place(&root);
	//printf("test\n");
	if (!solved(&root))
	{
		solver(&root);
	}
	//printf("total moves: %lu\n", root.i_count);
	// put_instruction(&root, 4);
	//print_stacks(&root);
	// put_instruction(&root, 4);
	// put_instruction(&root, 4);
	// print_stacks(&root);
	//
	// put_instruction(&root, 4);
	// print_stacks(&root);
	// put_instruction(&root, 4);
	// print_stacks(&root);
	//
	// put_instruction(&root, 3);
	// print_stacks(&root);
	// put_instruction(&root, 3);
	// print_stacks(&root);
	// printf("%i\n", get_index(root.a, root.a->head->next));
	// printf("%i\n", get_nth(root.a, 3)->data);
	//printf("%i\n", find_pivot(root.b, root.a->head->data));
	//printf("test\n");
	//tmp = root.a->head;
	// while (root.asize > 0)
	// {
	// 	printf("%i\t", tmp->data);
	// 	tmp = tmp->next;
	// 	root.asize--;
	// }
}

void 	print_stacks(t_ledger *root)
{
	t_node	*sa;
	t_node	*sb;
	int		bsize;
	int		asize;

	bsize = root->bsize;
	asize = root->asize;
	sa = root->a->head;
	sb = root->b->head;
	printf("\nStack visualization:\n");
	while (bsize > 0 || asize > 0)
	{
		if (asize > bsize || asize == bsize)
		{
			printf("%d\t", sa->data);
			asize--;
			sa = sa->next;
		}
		else
			printf("\t");
		if (bsize > asize + 1 || bsize == asize + 1)
		{
			printf("%d\t", sb->data);
			bsize--;
			sb = sb->next;
		}
		printf("\n");
	}
	printf("_\t_\n");
	printf("a\tb\n");
	if (root->bsize != 0)
		printf("max: %i min: %i\n", root->b->max->data, root->b->min->data);
}
