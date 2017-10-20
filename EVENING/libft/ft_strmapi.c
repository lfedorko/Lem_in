/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:58:40 by askochen          #+#    #+#             */
/*   Updated: 2016/12/01 15:05:33 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr1;
	char	*ptr2;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		ptr1 = ft_strnew(ft_strlen(s));
		ptr2 = ptr1;
		if (ptr1 != NULL)
		{
			while (*s != '\0')
			{
				*ptr2 = f(i, *s);
				++s;
				++ptr2;
				++i;
			}
		}
		return (ptr1);
	}
	return (NULL);
}
