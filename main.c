#include <stdio.h>
#include "lem_in.h"

void print_error(char *string, char **line)
{

	printf("%s\n", string);
	ft_strdel(line);
	exit(0);
}


int main()
{
	// init structure
	t_info *info;
	//t_room *room;

	info = (t_info *)malloc(sizeof(t_info));
	init_info(info);
	validation(info);
	free(info);

	return (0);
}