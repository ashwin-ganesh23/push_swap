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
	t_node		*tmp;

	if (argc < 2)
		exit(0);
	if (!initialize_ledger(&root))
		return (0);
	parse_pargs(&root, argc, argv);
	// set_place(&root);
	solver(&root);
	tmp = root.a->head;
	while (root.asize > 0)
	{
		printf("%i\t", tmp->data);
		tmp = tmp->next;
		root.asize--;
	}
}
