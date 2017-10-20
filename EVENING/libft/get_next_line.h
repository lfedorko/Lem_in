/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askochen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:29:07 by askochen          #+#    #+#             */
/*   Updated: 2017/03/15 10:00:25 by askochen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"
# include <unistd.h>

# define BUFF_SIZE 4

typedef struct	s_content
{
	char		*buf;
	int			fd;
	int			read_to_buf;
}				t_content;

int				get_next_line(const int fd, char **line);
#endif
