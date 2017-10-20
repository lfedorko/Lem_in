/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:26:19 by askochen          #+#    #+#             */
/*   Updated: 2016/12/09 12:43:01 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		ft_swap_char((str + i), (str + len - i - 1));
		++i;
	}
	return (str);
}
