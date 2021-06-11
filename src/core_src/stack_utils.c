/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:40:44 by jonny             #+#    #+#             */
/*   Updated: 2021/04/26 09:57:47 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	remove_head(t_lst *stack)
{
	t_node	*tmp;

	if (stack->head)
	{
		tmp = stack->head->next;
		free(stack->head);
		if (tmp)
			tmp->prev = NULL;
		stack->head = tmp;
		stack->len--;
		if (stack->head == NULL)
			stack->tail = NULL;
	}
}

void	remove_tail(t_lst *stack)
{
	t_node	*tmp;

	if (stack->tail)
	{
		tmp = stack->tail->prev;
		free(stack->tail);
		if (tmp)
			tmp->next = NULL;
		stack->tail = tmp;
		stack->len--;
		if (stack->tail == NULL)
			stack->head = NULL;
	}
}

int	is_sorted(t_lst *stack, enum e_order order)
{
	int		next_nb;
	t_node	*ptr;

	ptr = stack->head;
	while (ptr)
	{
		if (ptr->next)
			next_nb = ptr->next->nb;
		else
			break ;
		if ((ptr->nb < next_nb && order == ASCENDING)
			|| (ptr->nb > next_nb && order == DESCENDING))
			ptr = ptr->next;
		else
			return (0);
	}
	return (1);
}

void	to_array(t_lst *stack, int *array)
{
	t_node	*ptr;
	int		i;

	i = 0;
	ptr = stack->head;
	while (ptr)
	{
		array[i] = ptr->nb;
		ptr = ptr->next;
		i++;
	}
}
