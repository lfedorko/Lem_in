/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:30:30 by askochen          #+#    #+#             */
/*   Updated: 2016/12/09 15:58:49 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstptr;
	unsigned const char	*srcptr;

	dstptr = (unsigned char *)dst;
	srcptr = (unsigned const char *)src;
	while ((int)--n >= 0)
	{
		*dstptr = *srcptr;
		dstptr++;
		dst++;
		if (*srcptr == (unsigned char)c)
			return (dst);
		srcptr++;
	}
	return (0);
}
