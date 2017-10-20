/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:58:26 by askochen          #+#    #+#             */
/*   Updated: 2016/12/05 17:47:59 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t	i;
	char	*temp;

	temp = s1;
	i = 0;
	while (*temp != '\0')
	{
		++temp;
	}
	while (*s2 != '\0' && i < len)
	{
		*temp = *s2;
		++temp;
		++s2;
		++i;
	}
	*temp = '\0';
	return (s1);
}
