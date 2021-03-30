/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:41:56 by chdespon          #+#    #+#             */
/*   Updated: 2021/03/30 16:25:11 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_includes.h"

void		quit(int i, t_engine *engine);

/*
** Parsing
*/

void		set_stack_a(t_engine *engine, char **list);
void		parse_arg(char **stack_a, t_engine *engine);

/*
** OP
*/

void		swap(t_list **stack);
void		swap_s(t_list **stack_a, t_list **stack_b);
void		rotate_r(t_list **stack_a, t_list **stack_b);
void		rotate(t_list **stack);
void		reverse(t_list **stack);
void		push(t_list **stack_a, t_list **stack_b);
void		reverse(t_list **stack);
void		reverse_r(t_list **stack_a, t_list **stack_b);

/*
** Structure
*/

t_engine	*malloc_engine(void);
t_engine	create_engine(void);

#endif