/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:54:58 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/24 14:07:41 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(int i)
{
	if (i == 0)
		ft_putstr(_RED"Error\nSome arguments are not integers\n"_WHITE);
	else if (i == 1)
		ft_putstr(_RED"Error\nSome arguments are bigger than an integer\n"_WHITE);
	else if (i == 2)
		ft_putstr(_RED"Error\nThere are duplicates\n"_WHITE);
	else if (i == 3)
		ft_putstr(_GREEN"OK\n"_WHITE);
	else if (i == 4)
		ft_putstr(_RED"KO\n"_WHITE);
	else if (i == 5)
		ft_putstr(_RED"Wrong operation\n"_WHITE);
	exit(0);
}
