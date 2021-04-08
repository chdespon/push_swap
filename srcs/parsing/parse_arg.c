/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:05:13 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/08 15:08:38 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_only_digit(char *str, t_engine *engine)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((ft_is_digit(str[i]) == false
			&& ft_is_whitespaces(str[i]) == false && str[i] != '-')
			|| (str[0] == '-' && str[1] == '\0')
			|| (i > 0 && str[i] == '-'
			&& (str[i - 1] != ' ' || ft_is_digit(str[i + 1]) == false)))
			quit(NOT_DIGIT, engine);
		i++;
	}
}

static void	check_duplicate_and_max_min_int(int ac, char **list,
															t_engine *engine)
{
	int i;
	int j;
	int len;

	len = ac - 1 - engine->verbose;
	engine->len_stack_a = len;
	i = engine->verbose;
	while (i < len + (int)engine->verbose)
	{
		if (ft_atoi(list[i]) > INT_MAX || ft_atoi(list[i]) < INT_MIN)
			quit(BIGGER_THAN_INT, engine);
		check_only_digit(list[i], engine);
		j = 1;
		while (j + i < len)
		{
			if (ft_atoi(list[i]) == ft_atoi(list[i + j]))
				quit(DUPLICATE, engine);
			j++;
		}
		i++;
	}
}

void		parse_arg(int ac, char **list, t_engine *engine)
{
	check_duplicate_and_max_min_int(ac ,list, engine);
}
