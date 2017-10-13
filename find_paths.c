/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:28:12 by lfedorko          #+#    #+#             */
/*   Updated: 2017/09/23 19:28:19 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	connect_room(t_pointer *p)
{
	int		i;
	t_room	*tmp;

	i = 0;
	tmp = p->room;
	p->info->conn = (t_room **)malloc(sizeof(t_room *) * p->info->room + 1);
	p->info->conn[p->info->room] = NULL;
	while (tmp && i < p->info->room)
	{
		p->info->conn[i] = tmp;
		i++;
		tmp = tmp->next;
	}
}

void	create_ant_positon(t_pointer *p)
{
	t_path	*tmp;

	tmp = p->path;
	while (tmp)
	{
		tmp->position = (int *)ft_memalloc(sizeof(int) * tmp->len);
		if (p->info->p_p[1] < tmp->len)
			p->info->p_p[1] = tmp->len;
		p->info->p_p[0]++;
		tmp = tmp->next;
	}
}

void	find_paths(t_pointer *p)
{
	int	*tmp_path;
	int i;

	tmp_path = (int *)ft_memalloc(sizeof(int) * p->info->room);
	p->info->used = ft_strnew(p->info->room);
	p->info->used = ft_memset(p->info->used, '0', p->info->room);
	dfs(0, 0, tmp_path, p);
	free(tmp_path);
	if (p->path == NULL)
		print_error("ERROR: no roads", p);
	sort_littlebig(p);
	sort_unique(p, p->info->used);
	connect_room(p);
	create_ant_positon(p);
	i = 0;
	while (i < p->info->size)
		ft_printf("%s\n", p->info->file[i++]);
	ft_printf("\n");
}
