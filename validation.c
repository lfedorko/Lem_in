#include <limits.h>
#include "lem_in.h"

void handle_rooms(t_room *rooms, t_info *pInfo);

void add_handle_rooms(t_room *room, t_info *info, char *s);


t_room *lst_new(t_room *room, char *s);
void check_digit(char *s);


void realloc_2d_array(t_info *info, char *line)
{
	int 	i;
	char	**new;

	i = -1;
	new = (char **)malloc(sizeof(char *) * (info->size + 2));
	while (++i < info->size)
		new[i] = info->file[i];
	if(info->file != NULL)
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
	rooms = (t_room *)malloc(sizeof(t_room));
	rooms->name = NULL;
	handle_rooms(rooms, info);

}

void handle_rooms(t_room *rooms, t_info *info)
{
	char *line;

	while (get_next_line(0, &line) > 0) {
		if (line[0] == '#') {
			if (ft_strcmp("##start", line) && info->s_e[0] == 0)
				info->s_e[0] = 1;
			else if (ft_strcmp("##end", line) && info->s_e[0] == 0)
				info->s_e[1] = 1;
			else if (line[1] == '#')
				print_error("ERROR: wrong rule", &line);
			if (info->s_e[0] && info->s_e[1])
				print_error("ERROR: rule after rule", &line);

			realloc_2d_array(info, line);

		}
		else
			add_handle_rooms(rooms, info, line);
		free(line);
	}
}
//проверка на два пробела +
//проверка на два числа +
//проверка на комнату room co
//проверку на кординаты
//проверка на старт/конец
//
void add_handle_rooms(t_room *room, t_info *info, char *s)
{
	check_digit(s);
	room = lst_new(room, s);
	printf("%s %d %d \n", room->name, room->coord[0], room->coord[1]);

}

t_room *lst_new(t_room *room, char *s);

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

t_room *lst_new(t_room *room, char *s)
{
	t_room *new;
	char *tmp;

	tmp = s;
	while (*tmp != ' ')
		tmp++;
	if (room->name == NULL)
		new = room;
	else
	{
		new = (t_room *)malloc(sizeof(t_room));
		new->next = room;
	}
	new->name = ft_strsub(s, 0, tmp - s);
	new->coord[0] = ft_atoi(tmp);
	tmp++;
	while (*tmp != ' ')
		tmp++;
	new->coord[1] = ft_atoi(tmp);
	return(new);
}
