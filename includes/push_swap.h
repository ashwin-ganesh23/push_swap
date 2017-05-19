#ifndef CHECKER_H
# define CHECKER_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <libft.h>
# include <get_next_line.h>
# include "checker.h"

typedef struct	s_node
{
	int 			data;
	struct s_node	*next;
	struct s_node	*prev;
	int				pos;
	int				score;
}				t_node;

typedef struct	s_stack
{
	struct s_node 	*head;
	struct s_node	*tail;
	struct s_node	*max;
	struct s_node	*min;
}				t_stack;

typedef	struct	s_ledger
{
	struct s_stack	*a;
	struct s_stack	*b;
	size_t 			asize;
	size_t			bsize;
	char 			**instructions;
}				t_ledger;

void		sa(t_ledger *stk);
void		sb(t_ledger *stk);
void		ss(t_ledger *stk);
void		pa(t_ledger *stk);
void		pb(t_ledger *stk);
void		ra(t_ledger *stk);
void		rb(t_ledger *stk);
void		rr(t_ledger *stk);
void		rra(t_ledger *stk);
void		rrb(t_ledger *stk);
void 		rrr(t_ledger *stk);

void 	(*g_stack[11])(t_ledger *stk);

t_node	*new_nodelst(int input);
int		insert_node(t_node *head, t_stack *master, int input);
int		get_index(t_stack *stack, t_node *input);
t_node	*get_nth(t_stack *stack, int i);;

t_node	*split(t_node *head);
t_node	*merge(t_node *first, t_node *second);
t_node	*merge_sort(t_node *head);

int 	initialize_ledger(t_ledger *ledger);
void	put_error();
void 	set_place(t_ledger *ledger);
ssize_t	ft_max_atoi(char *str);

void    parse_pargs(t_ledger *ledger, int argc, char **argv);
int 	check_duplicates(t_ledger *root, int n);
int     valid_int(char *str);
void 	parse_arg(t_ledger *ledger, char *arg);
int		get_length(char **args);

void 	put_instruction(t_ledger *root, int i);

void 	solver(t_ledger *root);
int		calculate_score(t_ledger *ledger, int i);
int		optimal_score(t_ledger *ledger, int i, int pivot);
int		optimal_move(t_ledger *ledger, int i, int pivot);
int		find_pivot(t_stack *sb, int data);

int		small_solver(t_ledger *ledger);

void 	big_solver(t_ledger *root);
void	insert_b(t_ledger *ledger, int index);
int		get_insert(t_ledger *root);
void 	strat_one(t_ledger *ledger, int index, int pivot);
void 	strat_two(t_ledger *ledger, int index, int pivot);
void 	strat_three(t_ledger *ledger, int index, int pivot);


#endif
