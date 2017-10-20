#include "../corewar_vm.h"

void fork_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	new_process(pr, ms, arg->param[0] % IDX_MOD);
	ms->total_process++;
}
