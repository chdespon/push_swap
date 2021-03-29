/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:55:23 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/29 15:07:56 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	if (ft_lst_size(*stack) > 2)
	{
		while ((*stack)->next->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next->next = tmp;
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
	}
	if (ft_lst_size(*stack) == 2)
		reverse(stack);
}

void	reverse_r(t_list **stack_a, t_list **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}
