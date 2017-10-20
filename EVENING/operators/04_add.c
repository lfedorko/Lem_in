#include "../corewar_vm.h"


void add_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	if (arg->param[0] >= 1 && arg->param[0] <= REG_NUMBER
		&& arg->param[1] >= 1 && arg->param[1] <= REG_NUMBER
		&& arg->param[2] >= 1 && arg->param[2] <= REG_NUMBER)
	{
		pr->reg[arg->param[2]] = pr->reg[arg->param[0]] + pr->reg[arg->param[1]];
		if (pr->reg[arg->param[2]] == 0)
			pr->carry = 1;
		else
			pr->carry = 0;
	}
}