/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:15:17 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/13 14:45:00 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_100(t_engine *engine)
{
	int	len_stack_a;

	len_stack_a = engine->len_stack_a;
	set_chunk(engine, len_stack_a, 19);
	if (len_stack_a >= 20)
		set_chunk(engine, len_stack_a, 39);
	if (len_stack_a >= 40)
		set_chunk(engine, len_stack_a, 59);
	if (len_stack_a >= 60)
		set_chunk(engine, len_stack_a, 79);
	if (len_stack_a >= 80)
		set_chunk(engine, len_stack_a, 99);
	push_chunk_to_a(engine);
}
