/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:05:13 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/25 11:50:33 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_only_digit(char *str)
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
			quit(NOT_DIGIT);
		i++;
	}
}

static void	check_duplicate_and_max_min_int(char **list, int len)
{
	int i;
	int j;

	i = 1;
	while (i < len)
	{
		if (ft_atoi(list[i]) > INT_MAX || ft_atoi(list[i]) < INT_MIN)
			quit(BIGGER_THAN_INT);
		check_only_digit(list[i]);
		j = 1;
		while (j + i < len)
		{
			if (ft_atoi(list[i]) == ft_atoi(list[i + j]))
				quit(DUPLICATE);
			j++;
		}
		i++;
	}
}

void		parse_arg(char **list, int len)
{
	check_duplicate_and_max_min_int(list, len);
}
