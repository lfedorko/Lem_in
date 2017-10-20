/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_argc_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:50:04 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/16 17:50:06 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int 	ft_give_num_help(t_mstruc *inst)
{
	int i;
	int j;
	int flag;

	i = 0;
	while (++i <= MAX_PLAYERS)
	{
		j = -1;
		flag = 0;
		while (++j < MAX_PLAYERS)
		{
			if (inst->player_num[j] == i)
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
			break ;
	}
	return (i);
}

void	ft_give_num(t_players *ptr, int i, int j, t_mstruc *inst)
{
	while (ptr)
	{
		if (inst->player_num[i])
			ptr->pl_num = inst->player_num[i];
		else
		{
			ptr->pl_num = ft_give_num_help(inst);
			inst->player_num[i] = ptr->pl_num;
		}
		++i;
		ptr = ptr->next;
	}
}

int 	ft_check_repeat_num(t_mstruc *inst)
{
	int i;
	int j;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (inst->player_num[i] != 0)
		{
			j = -1;
			while (++j < MAX_PLAYERS)
			{
				if (j != i && inst->player_num[j] != 0)
					if (inst->player_num[i] == inst->player_num[j])
						return (1);
			}
		}
	}
	return (0);
}

void	ft_copy_player(t_players *des, t_players *src)
{
	int i;

	des->header = ft_init_header();
	des->header->magic = src->header->magic;
	des->header->prog_size = src->header->prog_size;
	i = -1;
	while (++i <= PROG_NAME_LENGTH)
		des->header->prog_name[i] = src->header->prog_name[i];
	i = -1;
	while (++i <= COMMENT_LENGTH)
		des->header->comment[i] = src->header->comment[i];
	des->opcode = src->opcode;
	des->pl_num = src->pl_num;
	des->live_flag = src->live_flag;
	des->last_live = src->last_live;
	des->next = NULL;
}

char	*ft_move_to_mas(t_mstruc *inst)
{
	int j;
	t_players *ptr;

	if (ft_check_repeat_num(inst))
		return (BAD_NUM_OF_PL);
	ft_give_num(inst->players, 0, -1, inst);
	j = 0;
	while (++j <= MAX_PLAYERS)
	{
		ptr = inst->players;
		while (ptr)
		{
			if (ptr->pl_num == j)
				ft_copy_player(&(inst->mas_player[j - 1]), ptr);
			ptr = ptr->next;
		}
	}
	return (NULL);
}
