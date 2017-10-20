/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:58:05 by askochen          #+#    #+#             */
/*   Updated: 2016/12/01 15:06:20 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr1;
	char	*ptr2;

	if (s != NULL && f != NULL)
	{
		ptr1 = ft_strnew(ft_strlen(s));
		ptr2 = ptr1;
		if (ptr1 != NULL)
		{
			while (*s != '\0')
			{
				*ptr2 = f(*s);
				++s;
				++ptr2;
			}
		}
		return (ptr1);
	}
	return (NULL);
}
