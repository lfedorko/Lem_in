#include "../corewar_vm.h"

void ldi_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	unsigned int		first;
	unsigned int		second;
	int 				sum;

	if (!(arg->param[2] >= 1 && arg->param[2] <= 16)
		|| (arg->type_param[1] == T_REG && !(arg->param[1] >= 1 && arg->param[1] <= 16))
		|| (arg->type_param[0] == T_REG && !(arg->param[0] >= 1 && arg->param[0] <= 16)))
		return ;
	if(arg->type_param[0] == T_REG) 
		first = pr->reg[arg->param[0]];
	else
		first = arg->param[0];
	if(arg->type_param[1] == T_REG) 
		second =  pr->reg[arg->param[1]];
	else
		second =  arg->param[1];
	sum = (first + second) % IDX_MOD;
	sum = get_pc(pr->pc + sum);
	pr->reg[arg->param[2]] = sum;
}