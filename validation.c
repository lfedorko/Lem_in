#include <limits.h>
#include "lem_in.h"

void handle_rooms(t_room *rooms, t_info *pInfo, t_pointer *pPointer);

t_room *add_handle_rooms(t_room *room, t_info *info, char *s, t_pointer *pPointer);


t_room *lst_new(t_room *room, char *s, t_info *pInfo, t_pointer *pPointer);
void check_digit(char *s, t_pointer *pPointer);

//1 general
void realloc_2d_array(t_info *info, char *line)
{
	int 	i;
	char	**new;

	i = -1;
	new = (char **)malloc(sizeof(char *) * (info->size + 2));
	while (++i < info->size)
		new[i] = info->file[i];
	if (info->file != NULL)
		free(info->file);
	new[info->size] = line;
	new[info->size + 1] = NULL;
	info->file = new;
	info->size++;
}

//2 ants
void number_of_ants(t_info *info, t_pointer *p)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (info->ants == 0 && get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			if (line[1] == '#')
				print_error("ERROR: rules before amount of ants",p);
		}
		else
		{
			info->ants = ft_atoi(line);
			while(line[i] && ft_isdigit(line[i]))
				i++;
			if (!(info->ants > 0 && info->ants <= INT_MAX)
				|| line[i] != '\0' || *line == '\0')
				print_error("ERROR: incorrect amount of ants", p);
		}
		realloc_2d_array(info, line);
	}
	if (line == NULL)
		print_error("ERROR: empty file", p);
}


void handle_path(t_room *room, t_info *info, t_pointer *p);
//3 general
void validation(t_info *info, t_pointer *p)
{
	t_room *rooms;

	number_of_ants(info, p);
	handle_rooms(rooms, info, p);
	handle_path(rooms, info, p);

}
// уникальность комнат
// уникальность соединений
// проверка
//
//
//
//part 3
void handle_path(t_room *room, t_info *info, t_pointer *p)
{

}
// part 2
void handle_rooms(t_room *rooms, t_info *info, t_pointer *p)
{

	int  i;
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (strchr(line, ' ') == NULL && strchr(line, '-') != NULL)
			break;
		if (line[0] == '#')
		{
			if (!ft_strcmp("##start", line) && info->s_e[0] == 0)
				info->s_e[0] = 1;
			else if (!ft_strcmp("##end", line) && info->s_e[1] == 0)
				info->s_e[1] = 1;
			else if (line[1] == '#')
				print_error("ERROR: wrong rule", p);
			else if (info->s_e[0] == 1 || info->s_e[1] == 1)
				print_error("ERROR: no room after rule", p);
		}
		else
		{
			rooms = add_handle_rooms(rooms, info, line, p);
		}
		realloc_2d_array(info, line);
	}
	i = 0;
	while (i < info->size)
		printf("%s\n",info->file[i++]);
	write(1, "opop",4);
}
//part 2
t_room *add_handle_rooms(t_room *room, t_info *info, char *s, t_pointer *p)
{
//	t_room *test;

	check_digit(s, p);
	if (!info->room)
		room = NULL;
	room = lst_new(room, s, info, p);
//	test = room;
//	while(test != NULL)
//	{
//		printf("%s %d %d %d\n", test->name, test->coord[0], test->coord[1], test->coord[2]);
//		test = test->next;
//	}
	return(room);
}

t_room *lst_new(t_room *room, char *s, t_info *pInfo, t_pointer *pPointer);
// general
void check_digit(char *s, t_pointer *p)
{
	int i;
	int	counter;

	i = -1;
	counter = 0;
	while (s[++i])
		if (s[i] == ' ' && ft_isdigit(s[i + 1]))
			counter++;
	if (counter != 2)
		print_error("ERROR:1 incorrect room", p);
	i = 0;
	if (s[i] == 'L')
		print_error("ERROR: 2 incorrect room", p);
	while (s[i] != ' ')
		i++;
	i++;
	while(s[i] != ' ')
		(ft_isdigit(s[i])) ? i++ : print_error("ERROR: invalid coord", p);
	i++;
	while (s[i] != '\0')
		(ft_isdigit(s[i])) ? i++ : print_error("ERROR: invalid coord", p);
}
//   part 2 - 3
void lst_cmp(t_room *r, t_room *new, t_pointer *p, int flag);
//8
t_room *lst_new(t_room *room, char *s, t_info *pInfo, t_pointer *p)
{
	t_room *new;
	char *tmp;

	tmp = s;
	new = (t_room *)malloc(sizeof(t_room));
	while (*tmp != ' ')
		tmp++;
	new->name = ft_strsub(s, 0, tmp - s);
	new->coord[0] = ft_atoi(tmp);
	tmp++;
	while (*tmp != ' ')
		tmp++;
	new->coord[1] = ft_atoi(tmp);
	lst_cmp(room, new, p, 0);
	new->next = room;
	new->coord[2] = 0;
	if (pInfo->s_e[0] == 1)
		new->coord[2] = pInfo->s_e[0]++;
	else if (pInfo->s_e[1] == 1)
	{
		pInfo->s_e[1]++;
		new->coord[2] = 3;
	}
	pInfo->room++;
	return (new);
}

void lst_cmp(t_room *r, t_room *new, t_pointer *p, int flag)
{
	if (!flag)
	{
		while (r != NULL)
		{
			if(!ft_strcmp(r->name, new->name))
				print_error("ERROR: same name", p);
			if (new->coord[0] == r->coord[0] && new->coord[1] == r->coord[1])
				print_error("ERROR: same coord",p);
			r = r->next;
		}
	}
	else
	{
//		while (r != NULL)
//		{
//			if (ft_strcmp(r->name, room))
		print_error("ERROR: invalid room", p);


	}
}

