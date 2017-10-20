/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 20:26:52 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/14 20:26:53 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int 	ft_lst_len(void *lst, int flag, int len)
{
	t_players *player;
	t_process *process;

	player = NULL;
	process = NULL;
	if (flag == 1)
	{
		player = (t_players *)lst;
		while (player)
		{
			len++;
			player = player->next;
		}
		return (len);
	}
	else
	{
		process = (t_process *)lst;
		while (process)
		{
			len++;
			process = process->next;
		}
		return (len);
	}
}

void	*ft_lst_end(void *lst, int flag)
{
	t_players *player;
	t_process *process;

	player = NULL;
	process = NULL;
	if (flag == 1)
	{
		player = (t_players *)lst;
		while (player->next)
			player = player->next;
		return ((void *)player);
	}
	else
	{
		process = (t_process *)lst;
		while (process->next)
			process = process->next;
		return ((void *)process);
	}
}
