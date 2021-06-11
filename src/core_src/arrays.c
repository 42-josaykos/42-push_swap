/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:35:41 by jonny             #+#    #+#             */
/*   Updated: 2021/04/26 09:59:58 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include <pthread.h>

int	strslen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_2darray(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free((void *)array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

static void	bubble_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				bubble_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	get_median(t_lst *stack)
{
	int		i;
	int		*list;

	list = NULL;
	if (stack->len > 0)
	{
		list = ft_calloc(stack->len, sizeof(int));
		if (!list)
			return (0);
		to_array(stack, list);
		bubble_sort(list, stack->len);
		stack->median = list[stack->len / 2];
		free(list);
	}
	return (1);
}
