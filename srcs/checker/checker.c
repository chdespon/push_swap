/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:29 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/02 13:03:09 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_engine	*engine;

	if (ac == 1)
		return (0);
	engine = malloc_engine();
	if (ft_strcmp(av[1], "-v") == 0)
		engine->verbose = true;
	parse_arg(ac, av + 1, engine);
	read_output(engine);
	set_stack_a(engine, av + 1 + engine->verbose);
	apply_op(engine);
	if (is_sort(engine))
		quit(OK, engine);
	else
		quit(KO, engine);
	return (0);
}
