#include "push_swap.h"

void 	small_solver(t_ledger *ledger)
{
	while (ledger->bsize < 2)
	{
		put_instruction(ledger, 4);
	}
}
