/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:58:38 by lfedorko          #+#    #+#             */
/*   Updated: 2017/08/18 16:58:44 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_name(t_pointer *p, char *tmp, char *new)
{
	t_room	*test;
	int		counter[3];

	counter[2] = 0;
	counter[0] = -1;
	counter[1] = -1;
	if ((tmp = ft_strchr(p->line, '-')) == NULL)
		return (1);
	new = ft_strsub(p->line, 0, tmp - p->line);
	test = p->room;
	while (test)
	{
		if (!ft_strcmp(new, test->name))
			counter[0] = counter[2];
		if (!ft_strcmp(tmp + 1, test->name))
			counter[1] = counter[2];
		counter[2]++;
		test = test->next;
	}
	free(new);
	if (counter[0] == -1 || counter[1] == -1)
		return (1);
	p->info->map[counter[0]][counter[1]] = 'X';
	p->info->map[counter[1]][counter[0]] = 'X';
	return (0);
}

void	create_map(t_pointer *p)
{
	t_room	*second;
	int		i;

	i = 0;
	p->info->map = (char **)malloc(sizeof(char *) * p->info->room + 1);
	p->info->map[p->info->room] = NULL;
	while (i < p->info->room)
	{
		p->info->map[i] = ft_strnew(p->info->room);
		ft_memset(p->info->map[i], '0', p->info->room);
		i++;
	}
	if (p->room->coord[2] == 2)
	{
		second = p->room->next;
		p->room->next = second->next;
		second->next = p->room;
		p->room = second;
	}
}

void	handle_path(t_room *room, t_pointer *p)
{
	char	*tmp;
	char	*new;

	create_map(p);
	(check_name(p, tmp, new)) ? print_error("ERROR : no link", p) :
	realloc_2d_array(p->info, p->line);
	while (get_next_line(0, &(p->line)) > 0)
	{
		if (p->line[0] == '#')
		{
			if (!ft_strcmp("##end", p->line) || !ft_strcmp("##start", p->line))
				print_error("ERROR: rule", p);
		}
		else
		{
			if (check_name(p, tmp, new))
			{
				free(p->line);
				p->line = NULL;
				break ;
			}
		}
		realloc_2d_array(p->info, p->line);
		p->line = NULL;
	}
}
