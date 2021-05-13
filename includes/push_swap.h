/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:41:56 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/13 14:43:16 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_includes.h"

void		quit(int i, t_engine *engine);

/*
** checker
*/

void		apply_instruction(t_engine *engine);
void		set_op(char *str, t_engine *engine);
void		apply_op(t_engine *engine);
void		read_output(t_engine *engine);
int			is_sort(t_engine *engine);
void		print_stacks(t_engine *engine);

/*
** Push_swap
*/

void		print_op(t_engine *engine);
void		resolve_stack(t_engine *engine);
int			sort_stack_a(t_engine *engine);
void		resolve_5(t_engine *engine);
void		resolve_3(t_engine *engine);
void		resolve_100(t_engine *engine);
void		push_chunk_to_a(t_engine *engine);
void		set_chunk(t_engine *engine, int len_stack_a, int limit_chunk);


/*
** Parsing
*/

void		set_stack_a(t_engine *engine, char **list);
void		parse_arg(int ac, char **list, t_engine *engine);
void		set_stack_index(t_engine *engine);


/*
** OP
*/

void		reverse(t_list **stack, int len);
void		reverse_r(t_list **stack_a, t_list **stack_b, int len_a, int len_b);
void		swap(t_list **stack, int len);
void		swap_s(t_list **stack_a, t_list **stack_b, int len_a, int len_b);
void		rotate_r(t_list **stack_a, t_list **stack_b, int len_a, int len_b);
void		rotate(t_list **stack, int len);
void		push(t_list **dest, t_list **src, int *len_dest, int *len_src);

/*
** Structure
*/

t_engine	*malloc_engine(void);
t_engine	create_engine(void);

#endif
