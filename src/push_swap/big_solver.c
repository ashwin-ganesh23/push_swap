#include "../includes/push_swap.h"

void 	big_solver(t_ledger *root)
{
	while (root->bsize < 2)
	{
		put_instruction(root, 4);
	}
	while (!solved)
	{
		calculate_score(root);
		index = pick_score(root);
	}
}

void 	put_instruction(t_ledger *root, int i)
{
	printf("%s\n", root->instructions[i]);
}
