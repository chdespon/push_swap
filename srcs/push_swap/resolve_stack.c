/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:15:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/14 10:55:00 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
