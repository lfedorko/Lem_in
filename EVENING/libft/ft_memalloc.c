/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:37:29 by askochen          #+#    #+#             */
/*   Updated: 2016/11/29 16:06:21 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)malloc(size);
	if (ptr != NULL)
	{
		ft_bzero(ptr, size);
	}
	return (ptr);
}
