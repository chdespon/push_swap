/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:54:37 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/17 11:10:14 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_500(t_engine *engine)
{
	int	len_stack_a;
	int	i;

	len_stack_a = engine->len_stack_a;
	i = 34;
	while (i < len_stack_a)
	{
		set_chunk(engine, len_stack_a, i, 35);
		i += 35;
	}
	set_chunk(engine, len_stack_a, len_stack_a, engine->len_stack_a);
	push_chunk_to_a(engine);
}
