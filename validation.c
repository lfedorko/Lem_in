#include <limits.h>
#include "lem_in.h"

void handle_rooms(t_room *rooms, t_info *pInfo, t_pointer *pPointer);
void handle_path(t_room *room, t_pointer *p, char *s);
t_room *add_handle_rooms(t_room *room, t_info *info, char *s, t_pointer *pPointer);
void check_name(char *s, t_pointer *p);
t_room *lst_new(t_room *room, char *s, t_pointer *p);
void check_digit(char *s, t_pointer *pPointer);

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
	new[info->size] = ft_strdup(line);
	new[info->size + 1] = NULL;
	info->file = new;
	info->size++;
	line = NULL;
	free(line);
}

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

void validation(t_info *info, t_pointer *p)
{
	t_room *rooms;

	number_of_ants(info, p);
	handle_rooms(rooms, info, p);

}

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
	(info->s_e[0] != info->s_e[1]) ? print_error("ERROR: no start or end", p) : handle_path(rooms, p, line);
}

t_room *add_handle_rooms(t_room *room, t_info *info, char *s, t_pointer *p)
{
//	t_room *test;

	check_digit(s, p);
	if (!info->room)
		room = NULL;
	room = lst_new(room, s, p);
//	test = room;
//	while(test != NULL)
//	{
//		printf("%s %d %d %d\n", test->name, test->coord[0], test->coord[1], test->coord[2]);
//		test = test->next;
//	}
	p->room = room;
	return(room);
}

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

void lst_cmp(t_room *new, t_pointer *p);

t_room *lst_new(t_room *room, char *s, t_pointer *p)
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
	lst_cmp(new, p);
	new->next = room;
	new->coord[2] = 0;
	if (p->info->s_e[0] == 1)
		new->coord[2] = p->info->s_e[0]++;
	else if (p->info->s_e[1] == 1)
	{
		p->info->s_e[1]++;
		new->coord[2] = 3;
	}
	p->info->room++;
	return (new);
}

void lst_cmp(t_room *new, t_pointer *p)
{
		while (p->room != NULL)
		{
			if(!ft_strcmp(p->room->name, new->name))
				print_error("ERROR: same name", p);
			if (new->coord[0] == p->room->coord[0]
				&& new->coord[1] == p->room->coord[1])
				print_error("ERROR: same coord",p);
			p->room = p->room->next;
		}
}

void handle_path(t_room *room, t_pointer *p, char *s)
{
	char *tmp;
	char *new;
	int  i;

	check_name(s, p);
	while (get_next_line(0,&s) >0)
	{
		check_name(s, p);
		//добавить штуки для обработки комментов и правил
		//добавить матрицу смежности
		// понять что происходит (логику)
	}
	printf("lalala");
	i = 0;
	while (i < p->info->size)
		printf("%s\n",p->info->file[i++]);
}

void check_name(char *s, t_pointer *p)
{
	t_room 	*test;
	int		count;
	char	*tmp;
	char 	*new;

	count = 0;
	tmp = s;
	while (*tmp != '-')
		tmp++;
	new = ft_strsub(s, 0, tmp - s);
	tmp++;
	test = p->room;
	while (test != NULL)
	{
		if (!ft_strcmp(new , test->name))
			count++;
		if (!ft_strcmp(tmp, test->name))
			count++;
		test = test->next;
	}
	if (count != 2)
		print_error("ERROR: alien name", p);
	realloc_2d_array(p->info, s);
}