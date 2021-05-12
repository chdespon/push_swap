/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_constructeur.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:19:52 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/12 12:45:33 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_engine	create_engine(void)
{
	t_engine	result;

	result.stack_a = NULL;
	result.stack_b = NULL;
	result.op = NULL;
	result.len_stack_a = 0;
	result.len_stack_b = 0;
	result.last_node = 0;
	result.verbose = false;
	return (result);
}

t_engine	*malloc_engine(void)
{
	t_engine *result;

	result = (t_engine*)malloc(sizeof(t_engine));
	if (result == NULL)
		quit(ERROR_MALLOC, result);
	*result = create_engine();
	return (result);
}
