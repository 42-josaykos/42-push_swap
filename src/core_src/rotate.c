/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:08:44 by jonny             #+#    #+#             */
/*   Updated: 2021/04/13 10:33:30 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

/*
** ra, rb:
** top number goes to bottom
*/
void	rotate(t_lst *stack)
{
	int		tmp;
	t_node	*head_ptr;

	if (stack && stack->len > 1)
	{
		tmp = stack->head->nb;
		head_ptr = stack->head;
		while (stack && stack->head)
		{
			if (stack->head->next)
				stack->head->nb = stack->head->next->nb;
			stack->head = stack->head->next;
		}
		stack->head = head_ptr;
		stack->tail->nb = tmp;
	}
}

/*
** rra, rrb:
** bottom number goes to top
*/
void	reverse_rotate(t_lst *stack)
{
	int		tmp;
	t_node	*tail_ptr;

	if (stack && stack->len > 1)
	{
		tmp = stack->tail->nb;
		tail_ptr = stack->tail;
		while (stack && stack->tail)
		{
			if (stack->tail->prev)
				stack->tail->nb = stack->tail->prev->nb;
			stack->tail = stack->tail->prev;
		}
		stack->tail = tail_ptr;
		stack->head->nb = tmp;
	}
}
