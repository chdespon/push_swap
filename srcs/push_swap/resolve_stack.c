/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:15:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/13 14:51:50 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_500(t_engine *engine)
{
	int	len_stack_a;

	len_stack_a = engine->len_stack_a;
	set_chunk(engine, len_stack_a, 44);
	if (len_stack_a >= 45)
		set_chunk(engine, len_stack_a, 89);
	if (len_stack_a >= 90)
		set_chunk(engine, len_stack_a, 134);
	if (len_stack_a >= 135)
		set_chunk(engine, len_stack_a, 179);
	if (len_stack_a >= 180)
		set_chunk(engine, len_stack_a, 224);
	if (len_stack_a >= 225)
		set_chunk(engine, len_stack_a, 269);
	if (len_stack_a >= 270)
		set_chunk(engine, len_stack_a, 314);
	if (len_stack_a >= 315)
		set_chunk(engine, len_stack_a, 359);
	if (len_stack_a >= 360)
		set_chunk(engine, len_stack_a, 225);
	if (len_stack_a >= 180)
		set_chunk(engine, len_stack_a, 225);
	if (len_stack_a >= 180)
		set_chunk(engine, len_stack_a, 225);
	if (len_stack_a >= 180)
		set_chunk(engine, len_stack_a, 225);
	push_chunk_to_a(engine);
}

void	resolve_stack(t_engine *engine)
{
	if (sort_stack_a(engine) == 1)
		return ;
	else if (engine->len_stack_a == 2)
	{
		swap(&engine->stack_a, engine->len_stack_a);
		ft_lst_add_back(&engine->op, ft_lst_create_node("sa"));
	}
	else if (engine->len_stack_a == 3)
		resolve_3(engine);
	else if (engine->len_stack_a <= 5)
		resolve_5(engine);
	else if (engine->len_stack_a <= 100)
		resolve_100(engine);
	else
		resolve_500(engine);
}
