/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 13:09:09 by lfedorko          #+#    #+#             */
/*   Updated: 2017/09/24 13:09:11 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_room(t_pointer *p)
{
	int		i;
	t_room	*tmp;
	t_room	*next;

	i = 0;
	tmp = p->room;
	while (i < p->info->room)
	{
		next = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = next;
		i++;
	}
}

void	free_path(t_pointer *p)
{
	t_path	*tmp;
	t_path	*next;
	int		i;

	i = 0;
	tmp = p->path;
	while (i < p->info->p_p[0])
	{
		next = tmp->next;
		free(tmp->road);
		free(tmp->position);
		free(tmp);
		tmp = next;
		i++;
	}
}

void	free_all(t_pointer *p)
{
	int	i;

	free(p->info->conn);
	free_room(p);
	free_path(p);
	i = -1;
	while (++i < p->info->room)
		free(p->info->map[i]);
	free(p->info->map);
	i = -1;
	while (++i < p->info->size)
		free(p->info->file[i]);
	free(p->info->file);
	free(p->info->used);
	free(p->info);
	free(p);
}

void	print_error(char *string, t_pointer *p)
{
	int	i;

	ft_printf("%s\n", string);
	if (p->room != NULL && p->room != NULL)
		free_room(p);
	if (p->line != NULL)
		free(p->line);
	if (p->info->used != NULL)
		free(p->info->used);
	if (p->info->map != NULL)
	{
		i = -1;
		while (++i < p->info->room)
			free(p->info->map[i]);
		free(p->info->map);
	}
	i = -1;
	while (++i < p->info->size)
		free(p->info->file[i]);
	if (p->info->file != NULL)
		free(p->info->file);
	free(p->info);
	free(p);
	while (1)
	{

	}
	exit(0);
}

int		main(void)
{
	t_info		*info;
	t_pointer	*p;
	t_room		*rooms;

	p = (t_pointer *)malloc(sizeof(t_pointer));
	info = (t_info *)malloc(sizeof(t_info));
	init_info(info, p);
	number_of_ants(info, p);
	handle_rooms(rooms, info, p);
	find_paths(p);
	p->path->len == 1 ? one_move(p) : move(p);
	free_all(p);
	return (0);
}
