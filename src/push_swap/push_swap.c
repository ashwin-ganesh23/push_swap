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
	// set_place(&root);
	//printf("test\n");

	solver(&root);

	//printf("test\n");
	//tmp = root.a->head;
	// while (root.asize > 0)
	// {
	// 	printf("%i\t", tmp->data);
	// 	tmp = tmp->next;
	// 	root.asize--;
	// }
}
