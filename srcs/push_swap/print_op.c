/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:55:37 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/14 11:51:03 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_engine *engine)
{
	t_list *tmp;

	tmp = engine->op;
	while (engine->op != NULL)
	{
		ft_putstr(engine->op->data);
		ft_putchar('\n');
		engine->op = engine->op->next;
	}
	engine->op = tmp;
}
