/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:27:43 by jonny             #+#    #+#             */
/*   Updated: 2021/04/30 11:00:33 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

bool	is_number(char *str)
{
	if (*str == '-')
	{
		str++;
		if (!(*str))
			return (false);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	print_stacks(t_lst *stack_a, t_lst *stack_b)
{
	t_node	*ptr_a;
	t_node	*ptr_b;

	ptr_a = NULL;
	ptr_b = NULL;
	if (stack_a && stack_a->len)
		ptr_a = stack_a->tail;
	if (stack_b && stack_b->len)
		ptr_b = stack_b->tail;
	ft_putstr_fd("\na:    ", STDERR_FILENO);
	while (ptr_a)
	{
		ft_putnbr_fd(ptr_a->nb, STDERR_FILENO);
		write(1, " ", 1);
		ptr_a = ptr_a->prev;
	}
	write(1, "\n", 2);
	ft_putstr_fd("b:    ", STDERR_FILENO);
	while (ptr_b)
	{
		ft_putnbr_fd(ptr_b->nb, STDERR_FILENO);
		write(1, " ", 1);
		ptr_b = ptr_b->prev;
	}
	write(1, "\n\n", 2);
}
