/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:34 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/23 12:42:24 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_is_digit(str[i]) == false && ft_is_whitespaces(str[i]) == false)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (check_arg(av[1]) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (0);
}