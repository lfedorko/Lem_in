#include "../corewar_vm.h"

void st_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	int position;

	if (arg->param[0] < 1 || arg->param[0] > REG_NUMBER)
		return;
	if (arg->type_param[1] == T_REG && arg->param[1] >= 1 
		&& arg->param[1] <= REG_NUMBER)
		pr->reg[arg->param[1]] = pr->reg[arg->param[0]];
	else
	{
		position = get_pc(pr->pc + arg->param[1] % IDX_MOD);
		value_to_memory(ms, position, pr->reg[arg->param[0]]);
	}
}
