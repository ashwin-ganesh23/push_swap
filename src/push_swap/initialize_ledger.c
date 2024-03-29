#include "../includes/push_swap.h"

int 	initialize_ledger(t_ledger *root)
{
	int 	i;

	i = 0;
	root->a = NULL;
	root->b = NULL;
	if ((root->a = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (0);
	if ((root->b = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (0);
	if ((root->instructions = (char**)malloc(sizeof(char*) * 11)) == NULL)
		return (0);
	while (i < 11)
	{
		if ((root->instructions[i++] = (char *)malloc(sizeof(char) * 4)) == NULL)
			return (0);
	}
	root->c_flag = 0;
	root->v_flag = 0;
	root->i_count = 0;
	root->asize = 0;
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

void 	set_place(t_ledger *ledger)
{
	size_t	i;
	int		j;
	t_node	*temp;
	t_node	*tmp;
	t_node 	*t;

	i = 0;
	tmp = ledger->a->head;
	temp = merge_sort(tmp);
	while (i < ledger->asize)
	{
		j = 0;
		t = temp;
		while (tmp->data != t->data)
		{
			t = t->next;
			j++;
		}
		tmp->pos = j;
		tmp = tmp->next;
		i++;
	}
}
