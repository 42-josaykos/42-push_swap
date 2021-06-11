/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:32:46 by jonny             #+#    #+#             */
/*   Updated: 2021/04/26 11:35:01 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	exec_instructions3(t_lst *stack_a, t_lst *stack_b, char *str)
{
	if (!ft_strncmp(str, "rrb", 3))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(str, "rb", 3))
		rotate(stack_b);
	else if (!ft_strncmp(str, "sb", 4))
		swap(stack_b);
	else if (!ft_strncmp(str, "ss", 3))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strncmp(str, "rr", 3))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strncmp(str, "rrr", 3))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

void	exec_instructions2(t_lst *stack_a, t_lst *stack_b, char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		swap(stack_a);
	else if (!ft_strncmp(str, "ra", 3))
		rotate(stack_a);
	else if (!ft_strncmp(str, "rra", 4))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(str, "pa", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(str, "pb", 3))
		push(stack_a, stack_b);
	else
		exec_instructions3(stack_a, stack_b, str);
}

void	exec_instructions(t_lst *stack_a, t_lst *stack_b, char *inst)
{
	char	**strs;
	int		i;

	(void)stack_b;
	strs = ft_split(inst, '\n');
	i = 0;
	while (strs[i])
	{
		exec_instructions2(stack_a, stack_b, strs[i]);
		i++;
	}
	free_2darray(strs);
}

int	get_nb_inst(char *buf)
{
	char	**tmp;
	int		len;

	tmp = ft_split(buf, '\n');
	len = strslen(tmp);
	free_2darray(tmp);
	return (len);
}
