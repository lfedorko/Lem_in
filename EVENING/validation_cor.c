/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_cor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:23:52 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/09 17:23:53 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

char *ft_prog_name(int fd, char *prog_name)
{
	ssize_t i;
	char *str;

	str = (char *)malloc(sizeof(char) * (PROG_NAME_LENGTH + 1 + 3));
	i = read(fd, str, (PROG_NAME_LENGTH + 1 + 3));
	if (i != (PROG_NAME_LENGTH + 1 + 3))
	{
		free(str);
		return (SMALL);
	}
	i = -1;
	while (str[++i] && (i < (PROG_NAME_LENGTH + 1 + 3)))
		prog_name[i] = str[i];
	free(str);
	return (NULL);
}

char *ft_prog_comment(int fd, char *comment)
{
	ssize_t i;
	char *str;

	str = (char *)malloc(sizeof(char) * (COMMENT_LENGTH + 1 + 3));
	i = read(fd, str, (COMMENT_LENGTH + 1 + 3));
	if (i != (COMMENT_LENGTH + 1 + 3))
	{
		free(str);
		return (SMALL);
	}
	i = -1;
	while (str[++i] && (i < (PROG_NAME_LENGTH + 1 + 3)))
		comment[i] = str[i];
	free(str);
	return (NULL);
}

 unsigned char *ft_read_op(int fd, int size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size);
	ft_bzero(str, size);
	if (read(fd, str, size) != size)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char *ft_validation_cor(int fd, t_players *player)
{
	char	line[4];
	char 	*str;

	if (read(fd, line, 4) != 4)
		return (SMALL);
	if ((player->header->magic = (unsigned int)ft_uint(0, line)) !=
		COREWAR_EXEC_MAGIC)
		return (HEADER);
	if ((str = ft_prog_name(fd, player->header->prog_name)) != NULL)
		return (str);
	if (read(fd, line, 4) != 4)
		return (SMALL);
	if ((player->header->prog_size = (unsigned int)ft_uint(0, line)) >
		CHAMP_MAX_SIZE)
		return (LARGE_CODE);
	if ((str = ft_prog_comment(fd, player->header->comment)) != NULL)
		return (str);
	if ((player->opcode = ft_read_op(fd, player->header->prog_size)) == NULL)
		return (DIFF_SIZE);
	return (NULL);
}