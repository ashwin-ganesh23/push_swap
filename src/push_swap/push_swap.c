#include "push_swap.h"

void 	(*g_funcs[11])(t_ledger *stk) =
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

void	put_error()
{
	ft_putstr("Error\n");
	exit (0);
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
	while (root.asize > 0)
	{
		print("%i\t", root.a->data);
		print("%i\n", root.a->pos);
		root.a = root.a->next;
	}
	solver(&root);
}
