/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:34:25 by chdespon          #+#    #+#             */
/*   Updated: 2021/04/01 11:50:01 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, int len)
{
	t_list *tmp;

	tmp = *stack;
	if (len < 2)
		return ;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lst_add_back(stack, tmp);
}

void	rotate_r(t_list **stack_a, t_list **stack_b, int len_a, int len_b)
{
	rotate(stack_a, len_a);
	rotate(stack_b, len_b);
}
