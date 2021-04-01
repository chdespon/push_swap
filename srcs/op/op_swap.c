/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:53:57 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/01 11:25:18 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, int len)
{
	void *tmp;

	tmp = NULL;
	if (len < 2)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

void	swap_s(t_list **stack_a, t_list **stack_b, int len_a, int len_b)
{
	swap(stack_a, len_a);
	swap(stack_b, len_b);
}
