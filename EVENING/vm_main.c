/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:17:28 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/04 20:17:29 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	ft_dell_mas(char **mas)
{
	int i;

	i = -1;
	while (mas[++i])
		free(mas[i]);
	free(mas);
}

t_players *ft_dell_players_lst(t_players *lst)
{
	t_players *ptr;

	if (lst)
	{
		while (lst)
		{
			if (lst->header)
				free(lst->header);
			if (lst->opcode)
				free(lst->opcode);
			ptr = lst;
			lst = lst->next;
			free(ptr);
		}
		return (NULL);
	}
	return (NULL);
}

t_process *ft_dell_process_lst(t_process *lst)
{
	t_process *ptr;

	if (lst)
	{
		while (lst)
		{
			ptr = lst;
			lst = lst->next;
			free(ptr);
		}
		return (NULL);
	}
	return (NULL);
}

void	ft_del_struct(t_mstruc *inst)
{
	if (inst->players)
		inst->players = ft_dell_players_lst(inst->players);
	if (inst->process)
		inst->process = ft_dell_process_lst(inst->process);
	free(inst);
}

void	ft_error_vm(char *error_mes, t_mstruc *inst, char **params, int i)
{
	write(2, "ERROR : ", 8);
	write(2, error_mes, ft_strlen(error_mes));
	if (i)
	{
		write(2, "  ", 2);
		write(2, params[i], ft_strlen(params[i]));
	}
	if (params)
		ft_dell_mas(params);
	if (inst)
		ft_del_struct(inst);
	exit(1);
}

int main(int argc, char **argv)
{
	t_mstruc *inst;
	char **params;
	int i;

	if (argc < 2)
	{
		write(0, USAGE, ft_strlen(USAGE));
		return(0);
	}
	params = (char **)malloc(sizeof(char *) * (argc + 1));
	i = 0;
	while (--argc > 0)
	{
		params[i] = ft_realloc(NULL, ft_strlen(argv[i + 1]), argv[i + 1]);
		i++;
	}
	params[i] = NULL;
	inst = ft_init_mstruct();
	ft_validation_arg(params, inst, -1);
	ft_choose_one(inst);
	ft_del_struct(inst);
	return (0);
}
