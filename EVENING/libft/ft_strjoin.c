/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:01:11 by askochen          #+#    #+#             */
/*   Updated: 2016/12/09 16:01:56 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (s1 != NULL && s2 != NULL)
	{
		ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (ptr != NULL)
		{
			ptr = ft_strcat(ptr, s1);
			ptr = ft_strcat(ptr, s2);
		}
		return (ptr);
	}
	return (NULL);
}
