/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:05:13 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/24 11:14:53 by chdespon         ###   ########.fr       */
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

static void	check_duplicate_and_max_min_int(char **stack_a, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		if (ft_atoi(stack_a[i]) > INT_MAX || ft_atoi(stack_a[i]) < INT_MIN)
			quit(BIGGER_THAN_INT);
		j = 1;
		while (j + i < len)
		{
			if (ft_strcmp(stack_a[i], stack_a[i + j]) == 0)
				quit(DUPLICATE);
			j++;
		}
		i++;
	}
}

void		parse_arg(char **stack_a, int len, char *str)
{
	check_duplicate_and_max_min_int(stack_a, len);
	check_only_digit(str);
}
