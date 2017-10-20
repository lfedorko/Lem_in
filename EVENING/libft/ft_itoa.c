/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:55:17 by askochen          #+#    #+#             */
/*   Updated: 2016/12/05 12:44:32 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_count(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (ft_count(-n) + 1);
	if (n == 0)
		return (1);
	if (n < 10)
		return (1);
	else
		return (ft_count(n / 10) + 1);
}

char			*ft_itoa(int number)
{
	char		*ptr;
	int			len;
	long int	n;
	char		*temp;

	n = number;
	len = ft_count(n);
	ptr = ft_strnew(len);
	if (ptr == NULL)
		return (NULL);
	temp = ptr;
	if (n < 0)
	{
		*(ptr++) = '-';
		n = n * -1;
		--len;
	}
	while (len > 0)
	{
		*(ptr + (len-- - 1)) = ('0' + n % 10);
		n = n / 10;
	}
	return (temp);
}
