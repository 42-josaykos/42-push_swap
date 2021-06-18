/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:38:15 by jonny             #+#    #+#             */
/*   Updated: 2021/06/18 12:37:35 by jonny            ###   ########.fr       */
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

void	get_chunk_array2(t_lst *stack)
{
	int	*tab;
	int	i;
	int	j;
	int	k;

	tab = ft_calloc(stack->len, sizeof(int));
	to_array(stack, tab);
	bubble_sort(tab, stack->len);
	stack->chunk_size = get_chunk_size(stack->len);
	stack->nb_chunks = stack->len / stack->chunk_size;
	stack->last_chunk_size = stack->len % stack->chunk_size;
	if (stack->last_chunk_size)
		stack->nb_chunks++;
	stack->chunks = ft_calloc(stack->chunk_size, sizeof(int));
	i = 0;
	while (i < stack->nb_chunks)
	{
		stack->chunks[i] = ft_calloc(stack->chunk_size, sizeof(int));
		i++;
	}
	i = 0;
	k = 0;
	while (i < stack->chunk_size)
	{
		j = 0;
		while (j < stack->chunk_size && k < stack->len)
		{
			stack->chunks[i][j] = tab[k];
			j++;
			k++;
		}
		i++;
	}
}

void	decr_pointer(t_pointer *node)
{
	node->ptr = node->ptr->prev;
	node->pos--;
}

void	free_chunk_arrays(int **arrays)
{
	int	i;

	i = 0;
	while (arrays[i])
	{
		free(arrays[i]);
		i++;
	}
	free(arrays);
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
