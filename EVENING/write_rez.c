/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_rez.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:33:23 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/20 14:33:24 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	ft_write_contestants(t_mstruc *inst, int i)
{
	char	*str;

	write(1, "Introducing contestants...", 26);
	write(1, "\n", 1);
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (inst->mas_player[i].pl_num)
		{
			write(1, "* Player", 8);
			str = ft_itoa(inst->mas_player[i].pl_num);
			write(1, str, ft_strlen(str));
			free(str);
			write(1, ", weighing", 10);
			str = ft_itoa(inst->mas_player[i].header->prog_size);
			free(str);
			write(1, str, ft_strlen(str));
			write(1, " bytes, \"", 9);
			write(1, inst->mas_player[i].header->prog_name,
				ft_strlen(inst->mas_player[i].header->prog_name));
			write(1, "\" (\"", 4);
			write(1, inst->mas_player[i].header->comment,
				  ft_strlen(inst->mas_player[i].header->comment));
			write(1, "\") !", 4);
		}
		write(1, "\n", 1);
	}
}
