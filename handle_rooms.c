/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:27:28 by lfedorko          #+#    #+#             */
/*   Updated: 2017/09/25 16:27:29 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*lst_cmp(t_room *new, t_pointer *p, char *s)
{
	char	*tmp;
	t_room	*tmp_room;

	tmp = s;
	tmp_room = p->room;
	new = (t_room *)malloc(sizeof(t_room));
	new->next = NULL;
	tmp = ft_strchr(tmp, ' ');
	new->name = ft_strsub(s, 0, tmp - s);
	new->coord[0] = ft_atoi(tmp);
	tmp++;
	tmp = ft_strchr(tmp, ' ');
	new->coord[1] = ft_atoi(tmp);
	while (tmp_room != NULL)
	{
		if (!ft_strcmp(tmp_room->name, new->name))
			print_error("ERROR: same name", p);
		if (new->coord[0] == tmp_room->coord[0]
			&& new->coord[1] == tmp_room->coord[1])
			print_error("ERROR: same coord", p);
		tmp_room = tmp_room->next;
	}
	return (new);
}

t_room	*lst_new(t_room *room, char *s, t_pointer *p)
{
	t_room		*new;
	t_room		*head;

	head = room;
	new = lst_cmp(new, p, s);
	if (p->info->s_e[0] == 1 || p->info->s_e[1] == 1)
	{
		new->coord[2] = (p->info->s_e[0] == 1 ? 1 : 2);
		if (p->info->s_e[0] == 1)
			p->info->s_e[0] = 2;
		else
			p->info->s_e[1] = 2;
		new->next = room;
		return (new);
	}
	new->coord[2] = 0;
	if (room == NULL)
		return (new);
	while (room->next != NULL)
		room = room->next;
	room->next = new;
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
		print_error("ERROR: incorrect room", p);
	i = 0;
	if (s[i] == 'L')
		print_error("ERROR:  incorrect name of room", p);
	while (s[i] != ' ')
		i++;
	i++;
	while (s[i] != ' ')
		(ft_isdigit(s[i])) ? i++ : print_error("ERROR: invalid coord", p);
	i++;
	while (s[i] != '\0')
		(ft_isdigit(s[i])) ? i++ : print_error("ERROR: invalid coord", p);
	i = -1;
	while (s[++i])
		if (s[i] == '-')
			print_error("ERROR: incorrect name (-)", p);
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
	while (get_next_line(0, &(p->line)) > 0)
	{
		if (strchr(p->line, ' ') == NULL && strchr(p->line, '-') != NULL)
			break ;
		if (p->line[0] == '#')
		{
			if (info->s_e[0] == 1 || info->s_e[1] == 1)
				print_error("ERROR: no room after rule", p);
			else if (!ft_strcmp("##start", p->line) && info->s_e[0] == 0)
				info->s_e[0] = 1;
			else if (!ft_strcmp("##end", p->line) && info->s_e[1] == 0)
				info->s_e[1] = 1;
			else if ((!ft_strcmp("##start", p->line) && info->s_e[0] == 2) ||
				(!ft_strcmp("##end", p->line) && info->s_e[1] == 2))
				print_error("ERROR: start/end already exist", p);
		}
		else
			rooms = add_handle_rooms(rooms, info, p->line, p);
		realloc_2d_array(info, p->line);
		p->line = NULL;
	}
	if (p->line == NULL)
		print_error("ERROR: no link", p);
	(info->s_e[0] != 2 || info->s_e[1] != 2) ?
	print_error("ERROR: no start/end", p) : handle_path(rooms, p);
}
