/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:02:26 by askochen          #+#    #+#             */
/*   Updated: 2016/11/29 16:10:29 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr;
	char	*ptr1;
	char	*ptr2;
	int		flag;
	int		i;

	i = -1;
	ptr = (char *)big;
	while (*ptr && (++i < ((int)len - (int)ft_strlen(little) + 1)))
	{
		flag = 1;
		ptr1 = ptr;
		ptr2 = (char *)little;
		while (*ptr2)
		{
			if (*ptr2 != *ptr1)
				flag = 0;
			ptr1++;
			ptr2++;
		}
		if (flag == 1)
			return (ptr);
		ptr++;
	}
	return (0);
}
