/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:38:15 by jonny             #+#    #+#             */
/*   Updated: 2021/06/14 14:59:25 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*get_chunk_array(t_lst *stack)
{
	int	*tab;

	tab = ft_calloc(stack->len, sizeof(int));
	to_array(stack, tab);
	bubble_sort(tab, stack->len);
	return (tab);
}

void	push_swap(t_lst *stack_a)
{
	t_lst	*stack_b;
	char	*buf;

	stack_b = NULL;
	buf = NULL;
	if (is_sorted(stack_a, ASCENDING))
		return ;
	init_stack(&stack_b, NULL);
	get_median(stack_a);
	if (stack_a->len < 3)
		exec_inst(stack_a, NULL, SA, &buf);
	else if (stack_a->len == 3)
		sort_3numbers(stack_a, &buf);
	else if (stack_a->len == 5)
		sort_5numbers(stack_a, stack_b, &buf);
	else
	{
		sort_a(stack_a, stack_b, &buf);
		stack_a = sort_b(stack_a, stack_b, &buf);
	}
	free_stack(stack_b);
	ft_putstr_fd(buf, STDOUT_FILENO);
	if (buf)
		free(buf);
}
