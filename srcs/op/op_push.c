/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:05:51 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/25 12:10:21 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dest, t_list **src, int *len_dest, int *len_src)
{
	t_list	*tmp;

	tmp = NULL;
	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_lst_add_front(dest, tmp);
	(*len_dest)++;
	(*len_src)--;
}
