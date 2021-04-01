/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:01:58 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/01 11:49:41 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_output(t_engine *engine)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret >= 1)
	{
		ft_putstr("Enter an operation... \"CTRL d\" to exit\n");
		ret = get_next_line(STDIN_FILENO, &line);
		set_op(line, engine);
	}
}
