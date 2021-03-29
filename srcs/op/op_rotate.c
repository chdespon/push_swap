/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:34:25 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/29 14:06:22 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	if (ft_lst_size(*stack) < 2)
		return ;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lst_add_back(stack, tmp);
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}