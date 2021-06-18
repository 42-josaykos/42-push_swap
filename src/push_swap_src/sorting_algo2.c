/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:52:48 by jonny             #+#    #+#             */
/*   Updated: 2021/06/18 12:36:50 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_pointer(t_lst *stack, t_pointer *node)
{
	node->ptr = stack->head;
	node->pos = 0;
}

void	incr_pointer(t_pointer *node)
{
	node->ptr = node->ptr->next;
	node->pos++;
}

void	init_rotate_inst(enum e_inst *r, enum e_inst *rr, enum e_stack lst)
{
	if (lst == B)
	{
		*r = RB;
		*rr = RRB;
	}
	else
	{
		*r = RA;
		*rr = RRA;
	}
}

void	handle_pos(t_lst *stack, t_pointer *node, char **buf, enum e_stack lst)
{
	enum e_inst	rotate;
	enum e_inst	reverse_rotate;

	init_rotate_inst(&rotate, &reverse_rotate, lst);
	if (node->pos < (stack->len / 2))
	{
		while (node->pos)
		{
			exec_inst(stack, NULL, rotate, buf);
			node->pos--;
		}
	}
	else
	{
		while (node->pos < stack->len)
		{
			exec_inst(stack, NULL, reverse_rotate, buf);
			node->pos++;
		}
		node->pos = 0;
	}
}

void	sort_5numbers(t_lst *a, t_lst *b, char **buf)
{
	int			next_nb;
	t_pointer	node;

	init_pointer(a, &node);
	while (node.ptr)
	{
		if (node.ptr->nb < a->median)
		{
			handle_pos(a, &node, buf, A);
			exec_inst(a, b, PB, buf);
			node.ptr = a->head;
			continue ;
		}
		incr_pointer(&node);
	}
	sort_3numbers(a, buf);
	if (b->head->nb < b->head->next->nb)
		exec_inst(b, NULL, SB, buf);
	while (b->len)
		exec_inst(b, a, PA, buf);
}
