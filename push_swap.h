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

typedef	struct	s_ledger
{
	int 	*a;
	int 	*b;
	int 	*ascores;
	size_t 	asize;
	size_t	bsize;
}				t_ledger;

#endif
