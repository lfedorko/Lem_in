/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 17:03:29 by lfedorko          #+#    #+#             */
/*   Updated: 2017/08/18 17:03:33 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lst_cmp(t_room *new, t_pointer *p)
{
	while (p->room != NULL)
	{
		if (!ft_strcmp(p->room->name, new->name))
			print_error("ERROR: same name", p);
		if (new->coord[0] == p->room->coord[0]
			&& new->coord[1] == p->room->coord[1])
			print_error("ERROR: same coord", p);
		p->room = p->room->next;
	}
}

t_room	*lst_new(t_room *room, char *s, t_pointer *p)
{
	t_room	*new;
	char	*tmp;
	t_room *head;

	tmp = s;
	head = room;
	new = (t_room *)malloc(sizeof(t_room));
	while (*tmp != ' ')
		tmp++;
	new->name = ft_strsub(s, 0, tmp - s);
	new->coord[0] = ft_atoi(tmp);
	tmp++;
	while (*tmp != ' ')
		tmp++;
	new->coord[1] = ft_atoi(tmp);
	lst_cmp(new, p);
	new->next = NULL;
	if (p->info->s_e[0] == 1 || p->info->s_e[1] == 1)
	{
		(p->info->s_e[0] == 1) ? (new->coord[2] = 1) : (new->coord[2] = 2);
		(p->info->s_e[0] == 1) ? (p->info->s_e[0] = 2) : (p->info->s_e[1] = 2);
		new->next = room;
		return (new);
	}
	if (room == NULL)
		return (new);
	while (room->next != NULL)
		room = room->next;
	room->next = new;
	new->coord[2] = 0;
	return (head);
}

void	check_digit(char *s, t_pointer *p)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (s[++i])
		if (s[i] == ' ' && ft_isdigit(s[i + 1]))
			counter++;
	if (counter != 2)
		print_error("ERROR:1 incorrect room", p);
	i = 0;
	if (s[i] == 'L')
		print_error("ERROR: 2 incorrect room", p);
	while (s[i] != ' ')
		i++;
	i++;
	while (s[i] != ' ')
		(ft_isdigit(s[i])) ? i++ : print_error("ERROR: invalid coord", p);
	i++;
	while (s[i] != '\0')
		(ft_isdigit(s[i])) ? i++ : print_error("ERROR: invalid coord", p);
}

t_room	*add_handle_rooms(t_room *room, t_info *info, char *s, t_pointer *p)
{
	check_digit(s, p);
	if (!info->room)
		room = NULL;
	room = lst_new(room, s, p);
	p->room = room;
	p->info->room++;
	return (room);
}

void	handle_rooms(t_room *rooms, t_info *info, t_pointer *p)
{
	char	*line;

	//p->line = line;
	while (get_next_line(0, &line) > 0)
	{
		if (strchr(line, ' ') == NULL && strchr(line, '-') != NULL)
			break ;
		if (line[0] == '#')
		{
			if (info->s_e[0] == 1 || info->s_e[1] == 1)
				print_error("ERROR: no room after rule", p);
			else if (!ft_strcmp("##start", line) && info->s_e[0] == 0)
				info->s_e[0] = 1;
			else if (!ft_strcmp("##end", line) && info->s_e[1] == 0)
				info->s_e[1] = 1;
			else if (line[1] == '#')
				print_error("ERROR: wrong rule", p);
			else if (info->s_e[0] == 1 || info->s_e[1] == 1)
				print_error("ERROR: no room after rule", p);
		}
		else
			rooms = add_handle_rooms(rooms, info, line, p);
		realloc_2d_array(info, line);
	}
	if (info->s_e[0] != info->s_e[1])
		print_error("ERROR: no start or end", p);
	handle_path(rooms, p, line);
}
