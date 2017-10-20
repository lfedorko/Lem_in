/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:00:48 by askochen          #+#    #+#             */
/*   Updated: 2016/12/01 15:17:52 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	if (s1 != NULL)
	{
		i = 0;
		ptr = ft_strnew(len);
		if (ptr != NULL)
		{
			while (i < len)
			{
				ptr[i] = s1[i + start];
				++i;
			}
			ptr[i] = '\0';
		}
		return (ptr);
	}
	return (NULL);
}
