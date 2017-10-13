/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:35:31 by lfedorko          #+#    #+#             */
/*   Updated: 2017/09/23 19:35:33 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		road_check(t_pointer *p, char *roads, int ant, int i)
{
	t_path	*tmp;

	p->path->position[0] = ++ant;
	ft_printf("\033[;33mL%d-%s\033[33;0m", ant,
	p->info->conn[p->path->road[0]]->name);
	tmp = p->path->next;
	while (i < p->info->p_p[0] && p->info->ants > ant)
	{
		if (roads[i] != 'X' && (tmp->len - p->path->len) < p->info->ants - ant)
		{
			ant++;
			tmp->position[0] = ant;
			ft_printf(" \033[;33mL%d-%s\033[33;0m", ant,
			p->info->conn[tmp->road[0]]->name);
		}
		else
		{
			roads[i] = 'X';
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (ant);
}

int		push_ants(t_pointer *p, int cur_ants, int exit_ants, int flag)
{
	t_path	*tmp;
	int		i;

	tmp = p->path;
	while (tmp)
	{
		i = tmp->len - 1;
		while (i > 0)
		{
			tmp->position[i] = tmp->position[i - 1];
			i--;
		}
		tmp->position[0] = 0;
		if (tmp->position[tmp->len - 1] != 0)
		{
			ft_printf("\033[;36mL%d-%s\033[33;0m", tmp->position[tmp->len - 1],
			p->info->conn[tmp->road[tmp->len - 1]]->name);
			flag++;
			if ((exit_ants + flag) < p->info->ants)
				ft_printf(" ");
		}
		tmp = tmp->next;
	}
	output_middle(p, cur_ants, 1, 0);
	return (flag);
}

void	output_middle(t_pointer *p, int cur_ants, int i, int flag)
{
	t_path	*tmp;

	while (i < p->info->p_p[1])
	{
		tmp = p->path;
		while (tmp)
		{
			if (tmp->len > i)
			{
				if (tmp->position[tmp->len - i - 1] != 0)
				{
					if (flag == 1)
						ft_printf(" ");
					ft_printf("L%d-%s", tmp->position[tmp->len - i - 1],
					p->info->conn[tmp->road[tmp->len - i - 1]]->name);
					flag = 1;
				}
			}
			tmp = tmp->next;
		}
		i++;
	}
	if (cur_ants < p->info->ants && flag == 1)
		ft_printf(" ");
}

void	move(t_pointer *p)
{
	int		exit_ants;
	char	*roads;
	int		cur_ants;

	exit_ants = 0;
	cur_ants = 0;
	roads = ft_strnew(p->info->p_p[0]);
	roads = ft_memset(roads, '0', p->info->p_p[0]);
	cur_ants = road_check(p, roads, cur_ants, 1);
	ft_printf("\n");
	while (exit_ants < p->info->ants)
	{
		exit_ants += push_ants(p, cur_ants, exit_ants, 0);
		if (p->info->ants - cur_ants > 0)
			cur_ants = road_check(p, roads, cur_ants, 1);
		ft_printf("\n");
	}
	free(roads);
}
