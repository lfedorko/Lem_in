/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_argc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:42:42 by sprosian          #+#    #+#             */
/*   Updated: 2017/10/11 21:42:43 by sprosian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

long int	ft_atoi_mod(char *str)
{
	long int	res;
	int			minus;

	res = 0;
	minus = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
		   *str == '\r' || *str == '\v' || *str == '\f')
		++str;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	return (res * minus);
}

char *ft_dump_num(int *ind, char **params, t_mstruc *inst)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	if (inst->dump_flag == -14570)
	{
		if (params[*ind + 1])
		{
			while (params[*ind + 1][++i])
			{
				if (ft_isdigit(params[*ind + 1][i]) == 0)
				{
					if (i == 0 && params[*ind + 1][i] == '-')
						;
					else
						flag++;
				}
			}
			*ind += 1;
			if (ft_strlen(params[*ind]) > 10 ||
					((inst->dump_flag = ft_atoi_mod(params[*ind])) >= INT_MAX ||
					 inst->dump_flag <= INT_MIN))
				flag++;
			if (flag)
				return (NUM_WRONG);
			return (NULL);
		}
		return (NUM_WRONG);
	}
	return (MULTIPLE_USE);
}

char	*ft_num_player(int *ind, char **params, t_mstruc *inst, int i)
{
	long int num;
	char *str;

	*ind += 1;
	if (params[*ind] && params[*ind + 1])
	{
		str = params[*ind];
		while (params[*ind][++i])
		{
			if (ft_isdigit(params[*ind][i]) == 0)
				return (NUM_WRONG);
		}
		num = ft_atoi_mod(params[*ind]);
		if (num < 1 || num > MAX_PLAYERS)
			return (NUM_WRONG);
		else
		{
			i = ft_lst_len(inst->players, 1, 0);
			if (i < MAX_PLAYERS)
			{
				inst->player_num[i] = num;
				*ind += 1;
				return (ft_create_new_player(*ind, params, inst));
			}
			else
				return (MANY_CHAMP);
		}
	}
	return (NUM_WRONG);
}

int 	ft_file_extension(char *str)
{
	char *ptr;
	int i;

	i = 0;
	if ((ptr = ft_strstr(str, ".cor")) == NULL)
		return (1);
	while (*ptr)
	{
		i++;
		ptr++;
	}
	if (i != 4)
		return (1);
	return (0);
}

char	*ft_create_new_player(int i, char **params, t_mstruc *inst)
{
	t_players	*tmp;
	int 		fd;
	char 		*str;

	inst->num_of_players += 1;
	tmp = inst->players;
	if (tmp)
	{
		tmp = (t_players *)ft_lst_end(tmp, 1);
		tmp->next = ft_init_players();
		tmp = tmp->next;
	}
	else
	{
		inst->players = ft_init_players();
		tmp = inst->players;
	}
	if (ft_file_extension(params[i]))
		return (EXTENSION);
	if ((fd = open(params[i], O_RDONLY)) < 0)
		return (CANT_READ);
	str = ft_validation_cor(fd, tmp);
	close(fd);
	return (str);
}

char *ft_check_bonus(t_mstruc *inst)
{
	if (inst->bonus_flag)
		return (MULTIPLE_USE);
	else
	{
		inst->bonus_flag += 1;
		return (NULL);
	}
}

void	ft_validation_arg(char **params, t_mstruc *inst, int i)
{
	char *fail;

	while (params[++i])
	{
		if (ft_strcmp(params[i], BONUS) == 0)
			fail = ft_check_bonus(inst);
		else if (ft_strcmp(params[i], DUMP) == 0)
			fail = ft_dump_num(&i, params, inst);
		else if (ft_strcmp(params[i], NUM) == 0)
			fail = ft_num_player(&i, params, inst, -1);
		else
			fail = ft_create_new_player(i, params, inst);
		if (fail)
			ft_error_vm(fail, inst, params, i);
	}
	if ((i = ft_lst_len(inst->players, 1, 0)) == 0)
		ft_error_vm(NOT_CHAMP, inst, params, -1);
	if (i > MAX_PLAYERS)
		ft_error_vm(MANY_CHAMP, inst, params, -1);
	if ((fail = ft_move_to_mas(inst)) != NULL)
		ft_error_vm(fail, inst, params, -1);
	ft_dell_mas(params);
}