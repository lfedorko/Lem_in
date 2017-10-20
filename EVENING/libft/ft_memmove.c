/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:22:17 by askochen          #+#    #+#             */
/*   Updated: 2016/12/05 17:42:16 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	psrc = (unsigned char*)src;
	pdest = (unsigned char*)dest;
	if (psrc < pdest)
		while ((int)len > 0)
		{
			len--;
			*(pdest + len) = *(psrc + len);
		}
	else
		pdest = ft_memcpy(pdest, psrc, len);
	return (dest);
}
