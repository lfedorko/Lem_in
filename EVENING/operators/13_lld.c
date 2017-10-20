#include "../corewar_vm.h"

void lld_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	if (arg->param[1] > 0 && arg->param[1] <= REG_NUMBER)
	{
		pr->reg[arg->param[1]] = arg->param[0];
		if (pr->reg[arg->param[1]] == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
	}
}