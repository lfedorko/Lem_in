#include <limits.h>
#include "lem_in.h"

void handle_rooms(t_room *rooms, t_info *pInfo);

t_room *add_handle_rooms(t_room *room, t_info *info, char *s);


t_room *lst_new(t_room *room, char *s, t_info *pInfo);
void check_digit(char *s);


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


void number_of_ants(t_info *info)
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
				print_error("ERROR: rules before amount of ants", &line);
		}
		else
		{
			info->ants = ft_atoi(line);
			while(line[i] && ft_isdigit(line[i]))
				i++;
			if (!(info->ants > 0 && info->ants <= INT_MAX)
				|| line[i] != '\0' || *line == '\0')
				print_error("ERROR: incorrect amount of ants", &line);
		}
		realloc_2d_array(info, line);
		free(line);
	}
	if (line == NULL)
		print_error("ERROR: empty file", &line);
}


void validation(t_info *info)
{
	t_room *rooms;

	number_of_ants(info);
	handle_rooms(rooms, info);


}

void handle_rooms(t_room *rooms, t_info *info)
{
	char *line;

	while (get_next_line(0, &line) > 0) {
		if (line[0] == '#')
		{
			if (!ft_strcmp("##start", line) && info->s_e[0] == 0)
				info->s_e[0] = 1;
			else if (!ft_strcmp("##end", line) && info->s_e[1] == 0)
				info->s_e[1] = 1;
			else if (line[1] == '#')
				print_error("ERROR: wrong rule", &line);
			else if (info->s_e[0] == 1 || info->s_e[1] == 1)
				print_error("ERROR: no room after rule", &line);
		}
		else
			rooms = add_handle_rooms(rooms, info, line);
		realloc_2d_array(info, line);
		free(line);
	}
}

//проверка на два пробела +
//проверка на два числа +
//проверка на комнату room co
//проверку на кординаты
//проверка на старт/конец +
//записать комнату и коорды +

t_room *add_handle_rooms(t_room *room, t_info *info, char *s)
{
//	t_room *test;

	check_digit(s);
	if (!info->room)
	{
		room = NULL;
		info->room = 1;
	}
	room = lst_new(room, s, info);
//	test = room;
//	while(test != NULL)
//	{
//		printf("%s %d %d %d\n", test->name, test->coord[0], test->coord[1], test->coord[2]);
//		test = test->next;
//	}
	return(room);
}

t_room *lst_new(t_room *room, char *s, t_info *pInfo);

void check_digit(char *s)
{
	int i;
	int	counter;

	i = -1;
	counter = 0;
	while (s[++i])
		if (s[i] == ' ' && ft_isdigit(s[i + 1]))
			counter++;
	if (counter != 2)
		print_error("ERROR: incorrect room", &s);
	i = 0;
	if (s[i] == 'L')
		print_error("ERROR: incorrect room", &s);
	while (s[i] != ' ')
		i++;
	i++;
	while(s[i] != ' ')
		(ft_isdigit(s[i])) ? i++ : print_error("ERROR: invalid coord", &s);
	i++;
	while (s[i] != '\0')
		(ft_isdigit(s[i])) ? i++ : print_error("ERROR: invalid coord", &s);
}

t_room *lst_cmp(t_room *r, t_room *new)
{
	while (r != NULL)
	{
		if(!ft_strcmp(r->name, new->name))
			print_error("ERROR: same name", NULL);
		if (new->coord[0] == r->coord[0] && new->coord[1] == r->coord[1])
			print_error("ERROR: same coord", NULL);
		r = r->next;
	}

}

t_room *lst_new(t_room *room, char *s, t_info *pInfo)
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
	lst_cmp(room, new);
	new->next = room;
	new->coord[2] = 0;
	if (pInfo->s_e[0] == 1)
		new->coord[2] = pInfo->s_e[0]++;
	else if (pInfo->s_e[1] == 1)
	{
		pInfo->s_e[1]++;
		new->coord[2] = 3;
	}
	return (new);
}
