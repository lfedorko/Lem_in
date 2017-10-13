/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:31:57 by lfedorko          #+#    #+#             */
/*   Updated: 2017/09/23 19:31:59 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_path(int *path, t_pointer *p, int depth)
{
	t_path	*new;
	t_path	*tmp;
	int		i;

	i = 0;
	new = (t_path *)malloc(sizeof(t_path));
	new->road = (int *)ft_memalloc(sizeof(int) * p->info->room);
	new->next = NULL;
	if (p->path == NULL)
		p->path = new;
	else
	{
		tmp = p->path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	while (i < depth)
	{
		new->road[i] = path[i];
		i++;
	}
	new->len = depth;
}

void	dfs(int start, int d, int *path, t_pointer *p)
{
	int	i;

	if (start == 1)
	{
		add_path(path, p, d);
		return ;
	}
	p->info->used[start] = '1';
	i = 0;
	while (i < p->info->room)
	{
		if (p->info->map[start][i] == 'X' && p->info->used[i] == '0')
		{
			path[d] = i;
			dfs(i, d + 1, path, p);
		}
		i++;
	}
	p->info->used[start] = '0';
}
