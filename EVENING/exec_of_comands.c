#include "corewar_vm.h"

void ft_comands(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	if (pr->operation >= 1 && pr->operation <= 10)
		ft_execution_of_comands(ms, pr, arg);
	else
		ft_execution_of_comands1(ms, pr, arg);
}

void ft_execution_of_comands(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	if (pr->operation == 1)
		live_com(ms, pr, arg);
	else if (pr->operation == 2)
		ld_com(ms, pr, arg);
	else if (pr->operation == 3)
		st_com(ms, pr, arg);
	else if (pr->operation == 4)
		add_com(ms, pr, arg);
	else if (pr->operation == 5)
		sub_com(ms, pr, arg);
	else if (pr->operation == 6)
		and_com(ms, pr, arg);
	else if (pr->operation == 7)
		or_com(ms, pr, arg);
	else if (pr->operation == 8)
		xor_com(ms, pr, arg);
	else if (pr->operation == 9)
		zjmp_com(ms, pr, arg);
	else if (pr->operation == 10)
		ldi_com(ms, pr, arg);
}

void ft_execution_of_comands1(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	if (pr->operation == 11)
		sti_com(ms, pr, arg);
	else if (pr->operation == 12)
		fork_com(ms, pr, arg);
	else if (pr->operation == 13)
		lld_com(ms, pr, arg);
	else if (pr->operation == 14)
		lldi_com(ms, pr, arg);
	else if (pr->operation == 15)
		lfork_com(ms, pr, arg);
	else if (pr->operation == 16)
		aff_com(ms, pr, arg);
}

/*void init_operators()
{
	operator = (op_type*)malloc(sizeof(op_type) * 16);
	operator[0] = live_com;
	operator[1] = ld_com;
	operator[2] = st_com;
	operator[3] = add_com;
	operator[4] = sub_com;
	operator[5] = and_com;
	operator[6] = or_com;
	operator[7] = xor_com;
	operator[8] = zjmp_com;
	operator[9] = ldi_com;
	operator[10] = sti_com;
	operator[11] = fork_com;
	operator[12] = lld_com;
	operator[13] = lldi_com;
	operator[14] = lfork_com;
	operator[15] = aff_com;
}

void ft_comands(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	operator[pr->operation](ms, pr, arg);
}

void ft_comands(t_mstruc *ms, t_process *pr, t_opcode *arg)
{
	if (pr->operation >= 0 && pr->operation <= 15)
	{
		operator[pr->operation](ms, pr, arg);
		if (pr->operation != 8)
		pr->pc = pr->pc + pr->opcode->row_size;
	}
}
*/