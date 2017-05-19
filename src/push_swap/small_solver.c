#include "push_swap.h"

int 	small_solver(t_ledger *ledger)
{
	if (ledger->asize == 1)
		return (0);
	while (ledger->bsize < 2)
	{
		put_instruction(ledger, 4);
	}
    return (0);
}
