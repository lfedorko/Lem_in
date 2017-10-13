/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:17:59 by lfedorko          #+#    #+#             */
/*   Updated: 2017/08/04 13:18:04 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_end(char *add_buffer, char **line)
{
	int	i;

	i = 0;
	if (add_buffer == NULL || *add_buffer == '\0')
		return (0);
	while (add_buffer[i] != '\0')
		i++;
	(*line) = ft_strncpy(ft_strnew(i), add_buffer, i);
	free(add_buffer);
	add_buffer = ft_strdup("\0");
	return (1);
}

static int	check_word(char **add_buffer, char **line)
{
	char	*new_buffer;
	int		i;

	i = 0;
	new_buffer = ft_strdup(*add_buffer);
	ft_strdel(add_buffer);
	while (new_buffer[i] != '\0' && new_buffer[i] != '\n')
		i++;
	if (new_buffer[i] == '\n')
	{
		(*line) = ft_strncpy(ft_strnew(i), new_buffer, i);
		*add_buffer = ft_strdup(new_buffer + i + 1);
		ft_strdel(&new_buffer);
		return (1);
	}
	*add_buffer = ft_strdup(new_buffer);
	ft_strdel(&new_buffer);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*add_buffer;
	char		buffer[BUFF_SIZE + 1];
	char		*new_buffer;
	int			i;

	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (add_buffer != NULL && check_word(&add_buffer, line))
		return (1);
	while ((i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		new_buffer = ft_strjoin(add_buffer, buffer);
		ft_strdel(&add_buffer);
		add_buffer = ft_strdup(new_buffer);
		ft_strdel(&new_buffer);
		if (check_word(&add_buffer, line))
			return (1);
	}
	if (i < 0)
		return (-1);
	return (check_end(add_buffer, line));
}
