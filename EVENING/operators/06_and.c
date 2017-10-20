#include "../corewar_vm.h"

void and_com(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	if ( arg->param[2] < 1 && arg->param[2] > REG_NUMBER)
		return;
	if (arg->type_param[0] == T_REG && arg->type_param[1] == T_REG
		&& (arg->param[0] >= 1 && arg->param[0] <= REG_NUMBER
		&& arg->param[1] >= 1 && arg->param[1] <= REG_NUMBER))
		pr->reg[arg->param[2]] = pr->reg[arg->param[0]] & pr->reg[arg->param[1]];
	else if (arg->type_param[0] != T_REG && arg->type_param[1] == T_REG
			&& (arg->param[1] >= 1 && arg->param[1] <= REG_NUMBER))
		pr->reg[arg->param[2]] = arg->param[0] & pr->reg[arg->param[1]];
	else if (arg->type_param[0] == T_REG && arg->type_param[1] != T_REG
			&& (arg->param[0] >= 1 && arg->param[0] <= REG_NUMBER))
		pr->reg[arg->param[2]] = pr->reg[arg->param[0]] & arg->param[1];
	else if (arg->type_param[0] != T_REG && arg->type_param[1] != T_REG)
		pr->reg[arg->param[2]] = arg->param[0] & arg->param[1];
	else
		return ;
	if (pr->reg[arg->param[2]] == 0)
		pr->carry = 1;
	else
		pr->carry = 0;
}