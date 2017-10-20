/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_war.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 18:49:42 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/16 18:49:44 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	ft_create_process(t_mstruc *inst)
{
	int i;
	t_process *process_lst;

	process_lst = ft_init_process();
	i = -1;
	while (++i < inst->num_of_players)
	{
		process_lst->reg[0] = inst->mas_player[i].pl_num * -1;
		process_lst->pc = MEM_SIZE / inst->num_of_players *
							(inst->mas_player[i].pl_num - 1);
		if ((i + 1) < inst->num_of_players)
		{
			process_lst->prev = ft_init_process();
			process_lst->prev->next = process_lst;
			process_lst = process_lst->prev;
		}
	}
	inst->process = process_lst;
}

void	ft_check_flags(t_mstruc *inst)
{

}

void	ft_fill_opcode_mem(t_mstruc *inst)
{
	int i;
	int j;
	int ind;

	i = -1;
	while (++i < inst->num_of_players)
	{
		ind = MEM_SIZE / inst->num_of_players *
				(inst->mas_player[i].pl_num - 1);
		j = -1;
		while (++j < inst->mas_player[i].header->prog_size)
		{
			inst->memory[ind] = inst->mas_player[i].opcode[j];
			ind++;
		}
	}
}

void	ft_validate_opcode(t_process *process, t_mstruc *inst, int *live_flag)
{
	int flag;

	if (live_flag && (inst->live_current_per >= NBR_LIVE ||
		*live_flag == MAX_CHECKS))
	{
		*live_flag = 0;
		if (inst->cycle_to_die > CYCLE_DELTA)
			inst->cycle_to_die -= CYCLE_DELTA;
		if (process->live_flag == 0)
			delete_process(process, inst);
	}
	else
	{
		if (process->op_cycle == -1)
		{
			process->opcode = ft_init_opcode();
			if ((flag = ft_opcode(process->pc, inst, process)) == 0)
				process->validation_flag = 1;
			process->op_cycle = op_tab[process->opcode->operation - 1].cycles;
			if (flag == 2)
				process->op_cycle = 1;
		}
		else if (process->op_cycle > 1)
			process->op_cycle--;
		else
		{
			if (process->validation_flag)
				ft_comands(inst, process, process->opcode);
			else
				process->pc += process->opcode->row_size;
			process->op_cycle = -1;
			free(process->opcode);
			process->opcode = NULL;
		}
	}
}

void	ft_core_war(t_mstruc *inst, int live_flag)
{
	t_process *lst;

	//ft_check_flags(inst);
	ft_write_contestants(inst, -1);
	while (inst->total_cycle != inst->dump_flag)
	{
		lst = inst->process;
		if (lst == NULL)
			return ;
		while (lst)
		{
			ft_validate_opcode(lst, inst, &live_flag);
			lst = lst->next;
		}
		inst->total_cycle++;
		if ((inst->total_cycle % inst->cycle_to_die) == 0)
			live_flag++;
	}
}

void	ft_core_war_viz(t_mstruc *inst, int live_flag)
{
	t_process *lst;
 	t_draw *draw;

  	draw = (t_draw *)malloc(sizeof(draw));
  	init_wind(draw); //статические элементы  
  	show_players(inst, draw);
	while (inst->total_cycle != inst->dump_flag)
	{
		output_core(inst, draw);
		wrefresh(draw->win[0]);
   		wrefresh(draw->win[1]);
		lst = inst->process;
		if (lst == NULL)
			return ;

		while (lst)
		{
			ft_validate_opcode(lst, inst, &live_flag);
			lst = lst->next;
		}
		inst->total_cycle++;
		if ((inst->total_cycle % inst->cycle_to_die) == 0)
			live_flag++;
		//sleep;
	}
	ft_destr_wins(draw);
}

void	ft_choose_one(t_mstruc *inst)
{
	int 		live_flag;

	ft_create_process(inst);
	ft_fill_opcode_mem(inst);
	live_flag = -1;
	if (inst->bonus_flag)
		ft_core_war_viz(inst, live_flag);
	else
		ft_core_war(inst, live_flag);
}