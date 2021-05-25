/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:55:23 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/25 12:10:41 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_list **stack, int len)
{
	t_list	*tmp;

	tmp = *stack;
	if (len > 2)
	{
		while ((*stack)->next->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next->next = tmp;
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
	}
	if (len == 2)
		swap(stack, len);
}

void	reverse_r(t_list **stack_a, t_list **stack_b, int len_a, int len_b)
{
	reverse(stack_a, len_a);
	reverse(stack_b, len_b);
}
