#include "../corewar_vm.h"

void lfork_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	new_process(pr, ms, arg->param[0]);
	ms->total_process++;
}
