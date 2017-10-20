/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:59:49 by askochen          #+#    #+#             */
/*   Updated: 2016/12/05 18:17:42 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((*s1 != '\0' && *s2 != '\0') && (i < n))
	{
		if (*s1 != *s2)
			return (0);
		++s1;
		++s2;
		++i;
	}
	if ((*s1 == '\0' && *s2 == '\0') || (i == n))
		return (1);
	return (0);
}
