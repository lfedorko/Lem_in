/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:14:05 by askochen          #+#    #+#             */
/*   Updated: 2016/12/09 12:19:49 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list *list, t_list *new)
{
	t_list *temp;

	if (list != NULL && new != NULL)
	{
		temp = list->next;
		list->next = new;
		new->next = temp;
	}
}
