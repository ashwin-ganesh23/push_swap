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
	int 			score;
}				t_node;

typedef struct	s_list
{
	struct s_node 	*head;
	struct s_node	*tail;
	struct s_node 	*max;
	struct s_node	*min;
}				t_list;

typedef	struct	s_ledger
{
	struct s_list	*a;
	struct s_list	*b;
	size_t 			asize;
	size_t			bsize;
	char 			**instructions;
}				t_ledger;

#endif
