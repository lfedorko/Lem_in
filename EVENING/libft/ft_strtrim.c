/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:59:01 by askochen          #+#    #+#             */
/*   Updated: 2016/12/02 15:47:05 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_spacess(char const *s)
{
	int	i;
	int	q;
	int	j;

	i = 0;
	q = 0;
	j = (int)ft_strlen(s) - 1;
	while (s[q] == ' ' || s[q] == '\n' || s[q] == '\t')
	{
		i++;
		q++;
		if (s[q] == '\0')
			return (i);
	}
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		i++;
		j--;
	}
	return (i);
}

static	int		ft_counter(char const *s)
{
	int	q;

	q = 0;
	while (s[q] == ' ' || s[q] == '\n' || s[q] == '\t')
		q++;
	return (q);
}

static	int		ft_rcounter(char const *s)
{
	int	j;

	j = (int)ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		j--;
	}
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*ptr;
	int		i;
	int		k;
	int		q;
	int		j;

	if (s == NULL)
		return (0);
	k = 0;
	i = ft_spacess(s);
	if (i == (int)ft_strlen(s))
		return (ft_strnew(0));
	q = ft_counter(s);
	j = ft_rcounter(s);
	ptr = (char *)malloc((int)ft_strlen(s) - i + 1);
	if (ptr == NULL)
		return (0);
	while (q != j + 1)
	{
		ptr[k] = s[q];
		q++;
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}
