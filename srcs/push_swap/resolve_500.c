/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:54:37 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/14 10:57:00 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	resolve_500_2(t_engine *engine, int len_stack_a)
{
	if (len_stack_a >= 315)
		set_chunk(engine, len_stack_a, 359, 45);
	if (len_stack_a >= 360)
		set_chunk(engine, len_stack_a, 404, 45);
	if (len_stack_a >= 405)
		set_chunk(engine, len_stack_a, 449, 45);
	if (len_stack_a >= 450)
		set_chunk(engine, len_stack_a, 494, 45);
	if (len_stack_a > 495)
		set_chunk(engine, len_stack_a, len_stack_a, engine->len_stack_a);
	push_chunk_to_a(engine);
}

void		resolve_500(t_engine *engine)
{
	int	len_stack_a;

	len_stack_a = engine->len_stack_a;
	set_chunk(engine, len_stack_a, 44, 45);
	if (len_stack_a >= 45)
		set_chunk(engine, len_stack_a, 89, 45);
	if (len_stack_a >= 90)
		set_chunk(engine, len_stack_a, 134, 45);
	if (len_stack_a >= 135)
		set_chunk(engine, len_stack_a, 179, 45);
	if (len_stack_a >= 180)
		set_chunk(engine, len_stack_a, 224, 45);
	if (len_stack_a >= 225)
		set_chunk(engine, len_stack_a, 269, 45);
	if (len_stack_a >= 270)
		set_chunk(engine, len_stack_a, 314, 45);
	resolve_500_2(engine, len_stack_a);
}
