/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:12:56 by askochen          #+#    #+#             */
/*   Updated: 2016/11/29 16:59:54 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*ptr;
	char	*ptr1;
	char	*ptr2;
	int		flag;

	ptr = (char *)big;
	if ((ft_strlen(big) == 0) && (ft_strlen(little) == 0))
		return ((char *)big);
	while (*ptr)
	{
		flag = 1;
		ptr1 = ptr;
		ptr2 = (char *)little;
		while (*ptr2)
		{
			if (*ptr1 != *ptr2)
				flag = 0;
			ptr1++;
			ptr2++;
		}
		if (flag == 1)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
