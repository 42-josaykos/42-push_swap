/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:13:41 by jonny             #+#    #+#             */
/*   Updated: 2021/06/18 13:44:35 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils.h"

typedef struct s_pointer
{
	t_node	*ptr;
	int		pos;
}			t_pointer;

enum	e_stack
{
	A,
	B
};

/*
** push_swap
*/
void	linear_check(t_lst *stack_a, t_lst *stack_b, char *buf);
void	push_swap(t_lst *stack_a);
int		*get_chunk_array(t_lst *stack);
void	get_chunk_array2(t_lst *stack);
int		get_chunk_size(int len);
int		get_first(t_lst *a, int *chunk, int size);
int		get_second(t_lst *a, int *chunk, int size);

int		sort_a(t_lst *a, t_lst *b);
t_lst	*sort_b(t_lst *a, t_lst *b);
void	sort_3numbers(t_lst *stack);
void	sort_5numbers(t_lst *a, t_lst *b);
void	exec_inst(t_lst *src, t_lst *dst, enum e_inst inst);
void	init_pointer(t_lst *stack, t_pointer *node);
void	incr_pointer(t_pointer *node);
void	decr_pointer(t_pointer *node);
void	handle_pos(t_lst *stack, t_pointer *node, enum e_stack lst);
void	free_chunk_arrays(int **arrays);

#endif