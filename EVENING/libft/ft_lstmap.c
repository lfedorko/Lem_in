/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:52:19 by askochen          #+#    #+#             */
/*   Updated: 2016/12/05 19:19:54 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*result;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((result = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	result = f(lst);
	result->next = ft_lstmap(lst->next, f);
	return (result);
}
