/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:21:44 by askochen          #+#    #+#             */
/*   Updated: 2016/12/05 17:48:20 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t i;
	size_t len;
	size_t j;
	size_t d;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	while (dst[i])
		i++;
	d = s - i - 1;
	if (i < s)
	{
		while (src[j] && (d > 0))
		{
			dst[i] = src[j];
			i++;
			j++;
			d--;
		}
		dst[i] = '\0';
		return (len);
	}
	return (s + ft_strlen(src));
}
