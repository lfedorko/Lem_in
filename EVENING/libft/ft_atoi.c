/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:48:08 by askochen          #+#    #+#             */
/*   Updated: 2016/11/25 19:49:38 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		minus;

	res = 0;
	minus = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\r' || *str == '\v' || *str == '\f')
		++str;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	return (res * minus);
}
