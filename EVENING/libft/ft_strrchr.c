/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:23:56 by askochen          #+#    #+#             */
/*   Updated: 2016/12/05 17:48:54 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp != '\0')
		++temp;
	while (temp >= s)
	{
		if (*temp == c)
			return (temp);
		--temp;
	}
	return (NULL);
}
