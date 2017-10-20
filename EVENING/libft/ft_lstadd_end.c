/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:11:18 by askochen          #+#    #+#             */
/*   Updated: 2016/12/09 14:14:40 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		if (*alst == NULL)
		{
			*alst = new;
			return ;
		}
		while ((*alst)->next != NULL)
		{
			*alst = (*alst)->next;
		}
		(*alst)->next = new;
	}
}
