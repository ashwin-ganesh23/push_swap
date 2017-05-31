#include "../includes/checker.h"

int 	initialize_stk(t_stack *root, int length)
{
	int 	i;

	i = 0;
	if ((root->a = (int *)malloc(sizeof(int) * (length + 1))) == NULL)
		return (0);
	if ((root->b = (int *)malloc(sizeof(int) * (length + 1))) == NULL)
		return (0);
	ft_bzero((void *)root->a, length + 1);
	ft_bzero((void *)root->b, length + 1);
	if ((root->instructions = (char**)malloc(sizeof(char*) * 11)) == NULL)
		return (0);
	while (i < 11)
	{
		if ((root->instructions[i++] = (char *)malloc(sizeof(char) * 4)) == NULL)
			return (0);
	}
	root->asize = 0;
	root->bsize = 0;
	root->instructions[0] = "sa\0\0";
	root->instructions[1] = "sb\0\0";
	root->instructions[2] = "ss\0\0";
	root->instructions[3] = "pa\0\0";
	root->instructions[4] = "pb\0\0";
	root->instructions[5] = "ra\0\0";
	root->instructions[6] = "rb\0\0";
	root->instructions[7] = "rr\0\0";
	root->instructions[8] = "rra\0";
	root->instructions[9] = "rrb\0";
	root->instructions[10] = "rrr\0";
	return (1);
}
