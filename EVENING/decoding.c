/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:34:20 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/09 17:34:21 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

char	*ft_realloc(char *ptr, int size, char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	if (ptr == NULL)
		i = 0;
	else
		i = (int)ft_strlen(ptr);
	if (!(tmp = (char *)malloc(sizeof(char) * (i + size + 1))))
		return (NULL);
	i = 0;
	while (ptr != NULL && ptr[i])
	{
		tmp[i] = ptr[i];
		i++;
	}
	j = -1;
	while (++j < size)
		tmp[i++] = buf[j];
	tmp[i] = '\0';
	if (ptr != NULL)
		free(ptr);
	return (tmp);
}

short ft_ushort(int ind, char *str)
{
	int i;
	unsigned short rez;
	unsigned short tmp;
	char line[2];

	line[0] = str[ind++];
	line[1] = str[ind];
	i = 0;
	rez = 0;
	while (i < 2)
	{
		tmp = (unsigned char)line[i];
		if (i == 0)
			tmp = (tmp << 8);
		rez += tmp;
		i++;
	}
	return ((short)rez);
}

int ft_uint(int ind, char *str)
{
	int i;
	unsigned int rez;
	unsigned int tmp;
	char line[4];

	line[0] = str[ind++];
	line[1] = str[ind++];
	line[2] = str[ind++];
	line[3] = str[ind];
	i = -1;
	rez = 0;
	while (++i < 4)
	{
		tmp = (unsigned char)line[i];
		if (i == 0)
			tmp = (tmp << 24);
		else if (i == 1)
			tmp = (tmp << 16);
		else if (i == 2)
			tmp = (tmp << 8);
		rez += tmp;
	}
	return ((int)rez);
}