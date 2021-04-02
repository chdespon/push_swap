/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:34 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/02 13:14:56 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_engine *engine;

	if (ac == 1)
		return (0);
	engine = malloc_engine();
	parse_arg(ac, av, engine);
	set_stack_a(engine, av);
	set_stack_index(engine);
	resolve_stack(engine);
	return (0);
}
