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

//матрица выводится
//первая комната - последняя комната
//освободить память в функции принт_ерор
//проверить валидацию окончательно

void print_results(t_pointer *p) {
	t_room *room;
	int i = 0;

	room = p->room;
	printf("ants = %d, rooms = %d\n", p->info->ants, p->info->room);
	while (room != NULL) {
		printf("name%s  start/end = %d\n", room->name, room->coord[2]);
		room = room->next;
	}

	while (i < p->info->room) {
		printf("%s\n", p->info->map[i]);
		i++;
	}
}

void	check_name(char *s, t_pointer *p)
{
	t_room	*test;
	char	*tmp;
	char	*new;
	int    counter[3];

	counter[2] = 0;
	counter[0] = -1;
	counter[1] = -1;
		tmp = s;
	while (*tmp != '-')
		tmp++;
	new = ft_strsub(s, 0, tmp - s);
	tmp++;
	test = p->room;
	while (test != NULL)
	{
		if (!ft_strcmp(new, test->name))
			counter[0] = counter[2];
		if (!ft_strcmp(tmp, test->name))
			counter[1] = counter[2];
		counter[2]++;
		test = test->next;
	}
	if (counter[0] == -1 || counter[1] == -1)
		print_error("ERROR: incorrect connections", p);
	p->info->map[counter[0]][counter[1]] = 'X';
}

void	handle_path(t_room *room, t_pointer *p, char *s)
{
	int		i;

	i = 0;
	p->info->map = (char **)malloc(sizeof(char *) * p->info->room + 1);
	p->info->map[p->info->room] = NULL;
	while(i < p->info->room)
	{
		p->info->map[i] = ft_strnew(p->info->room);
		ft_memset(p->info->map[i],'0',p->info->room);
		i++;
	}
	check_name(s, p);
	while (get_next_line(0, &s) > 0)
	{
		if (s[0] == '#')
		{
			if (!ft_strncmp("##", s, 2))
				print_error("ERROR: rule", p);
		}
		else
			check_name(s, p);
		realloc_2d_array(p->info, s);
	}
	printf("lalala\n");
	i = 0;
	while (i < p->info->size)
		printf("%s\n", p->info->file[i++]);
	print_results(p);
}
