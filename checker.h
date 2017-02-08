#ifndef CHECKER_H
# define CHECKER_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <get_next_line.h>
# include <libft.h>

typedef struct  s_stack
{
    int     *a;
    int     *b;
    size_t  asize;
    size_t  bsize;
}               t_stack;



#endif
