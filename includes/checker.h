#ifndef CHECKER_H
# define CHECKER_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <libft.h>
# include <get_next_line.h>

typedef struct  s_stack
{
	int     *a;
	int     *b;
	size_t  asize;
	size_t  bsize;
	char	**instructions;
}				t_stack;

extern void		(*g_funcs[11]) (t_stack *stk);

void		sa(t_stack *stk);
void		sb(t_stack *stk);
void		ss(t_stack *stk);
void		pa(t_stack *stk);
void		pb(t_stack *stk);
void		ra(t_stack *stk);
void		rb(t_stack *stk);
void		rr(t_stack *stk);
void		rra(t_stack *stk);
void		rrb(t_stack *stk);
void		rrr(t_stack *stk);


ssize_t	ft_max_atoi(char *str);
int     valid_int(char *str);
void	put_error();
int 	check_duplicates(t_stack *root, int n);
void 	check_instruction(t_stack *root, char *str);
int 	check_solution(t_stack *root);

void    parse_args(t_stack *root, int length, char **argv);
void    parse_arg(t_stack *root, char *arg);
int		get_length(char **args);;
int 	initialize_stk(t_stack *root, int length);
void 	print_stacks(t_stack *root);


#endif
