/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 16:55:48 by lfedorko          #+#    #+#             */
/*   Updated: 2017/08/18 16:55:53 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	realloc_2d_array(t_info *info, char *line)
{
	int		i;
	char	**new;

	i = -1;
	new = (char **)malloc(sizeof(char *) * (info->size + 2));
	while (++i < info->size)
		new[i] = info->file[i];
	if (info->file != NULL)
		free(info->file);
	new[info->size] = ft_strdup(line);
	new[info->size + 1] = NULL;
	info->file = new;
	info->size++;
	line = NULL;
	free(line);
}

void	number_of_ants(t_info *info, t_pointer *p, int i)
{
	char	*line;

	line = NULL;
	i = 0;
	while (info->ants == 0 && get_next_line(0, &line) > 0)
	{
		p->line = line;
		if (line[0] == '#')
		{
			if (!ft_strcmp("##end", line) || !ft_strcmp("##start", line))
				print_error("ERROR: rules before amount of ants", p);
		}
		else
		{
			info->ants = ft_atoi(line);
			while (line[i] && ft_isdigit(line[i]))
				i++;
			if (!(info->ants > 0 && info->ants <= INT_MAX)
				|| line[i] != '\0' || *line == '\0')
				print_error("ERROR: incorrect amount of ants", p);
		}
		realloc_2d_array(info, line);
	}
	if (line == NULL)
		print_error("ERROR: empty file", p);
}
