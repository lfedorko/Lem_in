/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:19:14 by askochen          #+#    #+#             */
/*   Updated: 2017/03/15 13:15:09 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_content	*get_element(t_list **lst, int fd)
{
	t_list		*temp;
	t_content	*content;

	temp = *lst;
	while (temp != NULL)
	{
		content = (t_content*)(temp->content);
		if (content->fd == fd)
			return (content);
		temp = temp->next;
	}
	content = (t_content*)malloc(sizeof(t_content));
	content->buf = ft_strnew(BUFF_SIZE);
	content->fd = fd;
	content->read_to_buf = -1;
	temp = (t_list*)malloc(sizeof(t_list));
	temp->content = (void*)content;
	temp->content_size = 1;
	ft_lstadd(lst, temp);
	return (content);
}

int			read_to_buffer(t_content *elem)
{
	char	*temp1;
	char	*temp2;

	temp1 = (char*)malloc(BUFF_SIZE + 1);
	elem->read_to_buf = read(elem->fd, temp1, BUFF_SIZE);
	temp1[elem->read_to_buf] = '\0';
	if (elem->read_to_buf == -1)
	{
		free(temp1);
		return (-1);
	}
	temp2 = ft_strjoin(elem->buf, temp1);
	free(elem->buf);
	free(temp1);
	elem->buf = temp2;
	return (0);
}

int			create_line(t_content *el, char **line)
{
	char	*res;
	char	*str;
	int		len;

	len = ft_strlen(el->buf);
	res = ft_strchr(el->buf, '\n');
	if (res != NULL)
	{
		*line = ft_strsub(el->buf, 0, res - (el->buf));
		str = ft_strsub(el->buf, res - (el->buf) + 1, len - (res - (el->buf)));
		free(el->buf);
		el->buf = str;
		return (1);
	}
	if (res == NULL && el->read_to_buf == 0)
	{
		*line = ft_strsub(el->buf, 0, len);
		free(el->buf);
		el->buf = ft_strnew(BUFF_SIZE);
		return (1);
	}
	len = read_to_buffer(el);
	if (len == -1)
		return (-1);
	return (2);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_content		*element;
	int				result;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	element = get_element(&list, fd);
	while (1)
	{
		if (element->read_to_buf == 0 && element->buf[0] == '\0')
			return (0);
		result = create_line(element, line);
		if (result == 1)
			return (result);
		if (result == -1)
			return (result);
		if (result == 0)
			return (0);
	}
}
