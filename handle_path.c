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

void	check_name(char *s, t_pointer *p)
{
	t_room	*test;
	int		count;
	char	*tmp;
	char	*new;

	count = 0;
	tmp = s;
	while (*tmp != '-')
		tmp++;
	new = ft_strsub(s, 0, tmp - s);
	tmp++;
	test = p->room;
	while (test != NULL)
	{
		if (!ft_strcmp(new, test->name))
			count++;
		if (!ft_strcmp(tmp, test->name))
			count++;
		test = test->next;
	}
	if (count != 2)
		print_error("ERROR: incorrect connections", p);
}

void	handle_path(t_room *room, t_pointer *p, char *s)
{
	char	*tmp;
	char	*new;
	int		i;

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
		//добавить штуки для обработки комментов и правил
		//добавить матрицу смежности
		//понять что происходит (логику)
	}
	printf("lalala\n");
	i = 0;
	while (i < p->info->size)
		printf("%s\n", p->info->file[i++]);
}
