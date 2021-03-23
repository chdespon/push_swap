/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:54:58 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/23 13:59:37 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(int i)
{
	if (i == 0)
		ft_putstr("Error\nSome arguments are not integers\n");
	else if (i == 1)
		ft_putstr("Error\nSome arguments are bigger than an integer\n");
	else if (i == 2)
		ft_putstr("Error\nThere are duplicates\n");
	exit(0);
}