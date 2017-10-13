/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfedorko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:42:35 by lfedorko          #+#    #+#             */
/*   Updated: 2017/09/25 16:42:39 by lfedorko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define BUFF_SIZE 10
# include "src_lib/libft/libft.h"
# include "src_lib/ft_printf/ft_printf.h"
# include <limits.h>
# include <fcntl.h>

typedef struct		s_room
{
	char			*name;
	int				coord[3];
	struct s_room	*next;
}					t_room;

typedef struct		s_path
{
	int				*road;
	int				*position;
	int				len;
	struct s_path	*next;
}					t_path;

typedef struct		s_info
{
	char			**map;
	int				room;
	int				ants;
	int				s_e[2];
	char			**file;
	int				size;
	int				p_p[2];
	char			*used;
	t_room			**conn;
}					t_info;

typedef struct		s_pointer
{
	t_room			*room;
	t_info			*info;
	t_path			*path;
	char			*line;
}					t_pointer;

int					get_next_line(const int fd, char **line);
void				print_error(char *string, t_pointer *p);
void				init_info(t_info *info, t_pointer *p);
void				number_of_ants(t_info *info, t_pointer *p);
void				realloc_2d_array(t_info *info, char *line);
void				handle_rooms(t_room *rooms, t_info *info, t_pointer *p);
void				handle_path(t_room *room, t_pointer *p);
void				find_paths(t_pointer *info);
void				sort_unique(t_pointer *p, char *used);
void				sort_littlebig(t_pointer *p);
void				dfs(int start, int d, int *path, t_pointer *p);
void				delete_node(t_pointer *p, t_path *list, t_path *prev);
void				connect_room(t_pointer *p);
void				move(t_pointer *p);
void				one_move(t_pointer *p);
void				output_middle(t_pointer *p, int cur_ants, int i, int flag);

#endif
