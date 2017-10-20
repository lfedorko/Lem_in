/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:07:04 by askochen          #+#    #+#             */
/*   Updated: 2016/12/05 17:47:22 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < len)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}
