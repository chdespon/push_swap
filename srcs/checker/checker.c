/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:29 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/01 16:09:58 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_engine *engine;

	if (ac == 1)
		return (0);
	engine = malloc_engine();
	if (engine == NULL)
		quit(ERROR_MALLOC, engine);
	parse_arg(ac, av, engine);
	read_output(engine);
	set_stack_a(engine, av + 1);
	apply_op(engine);
	set_stack_index(engine);
	if (is_sort(engine))
		quit(OK, engine);
	else
		quit(KO, engine);
	return (0);
}
