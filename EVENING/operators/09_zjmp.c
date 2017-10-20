#include "../corewar_vm.h"

void zjmp_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	if (pr->carry == 1)
	{
		pr->pc = get_pc(pr->pc + (arg->param[0] % IDX_MOD));
	}
}