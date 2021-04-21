/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:34:34 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/16 12:13:16 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_engine *engine;

	if (ac == 1)
		return (0);
	engine = malloc_engine();
	parse_arg(ac, av + 1, engine);
	set_stack_a(engine, av + 1);
	set_stack_index(engine);
	resolve_stack(engine);
	print_op(engine);
	return (0);
}
