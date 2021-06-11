/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:14:58 by jonny             #+#    #+#             */
/*   Updated: 2021/04/16 10:46:48 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

/*
** Add number to the stack. Add at the head of the list.
** Increment stack->len by 1
*/
void	prepend(t_lst *stack, int nb)
{
	t_node	*node;
	t_node	*tmp;

	node = ft_calloc(1, sizeof(t_node));
	node->nb = nb;
	node->prev = NULL;
	node->next = NULL;
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = stack->head;
		stack->len++;
	}
	else
	{
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
		stack->len++;
	}
}

/*
** Add number to the stack. Add at the tail of the list.
** Increment stack->len by 1
*/
void	append(t_lst *stack, int nb)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->nb = nb;
	node->prev = NULL;
	node->next = NULL;
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = stack->head;
		stack->len++;
	}
	else
	{
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->tail = stack->tail->next;
		stack->len++;
	}
}

/*
** Empty stack
*/
void	free_stack(t_lst *stack)
{
	t_node	*ptr;

	while (stack && stack->head)
	{
		ptr = stack->head->next;
		free(stack->head);
		stack->head = ptr;
	}
	if (stack)
		free(stack);
}

/*
** Init stack with numbers
*/
int	init_stack(t_lst **stack, char **args)
{
	int	i;

	*stack = ft_calloc(1, sizeof(t_lst));
	if (*stack == NULL)
	{
		free_2darray(args);
		return (1);
	}
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
	i = 0;
	while (args && args[i])
	{
		append(*stack, ft_atoi(args[i]));
		i++;
	}
	return (0);
}
