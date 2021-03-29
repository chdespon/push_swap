/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:53:57 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/29 14:07:08 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	void *tmp;

	tmp = NULL;
	if (ft_lst_size(*stack) < 2)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
