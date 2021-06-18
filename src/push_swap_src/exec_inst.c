/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:04:35 by jonny             #+#    #+#             */
/*   Updated: 2021/06/18 13:47:14 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exec_inst3(t_lst *src, t_lst *dst, enum e_inst inst)
{
	if (inst == RRA || inst == RRB)
	{
		reverse_rotate(src);
		if (inst == RRA)
			ft_putstr_fd("rra\n", STDOUT_FILENO);
		else if (inst == RRB)
			ft_putstr_fd("rrb\n", STDOUT_FILENO);
	}
	else if (inst == RRR)
	{
		reverse_rotate(src);
		reverse_rotate(dst);
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
	}
}

void	exec_inst2(t_lst *src, t_lst *dst, enum e_inst inst)
{
	if (inst == RA || inst == RB)
	{
		rotate(src);
		if (inst == RA)
			ft_putstr_fd("ra\n", STDOUT_FILENO);
		else if (inst == RB)
			ft_putstr_fd("rb\n", STDOUT_FILENO);
	}
	else if (inst == RR)
	{
		rotate(src);
		rotate(dst);
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	}
	else
		exec_inst3(src, dst, inst);
}

void	exec_inst(t_lst *src, t_lst *dst, enum e_inst inst)
{
	if (inst == SA || inst == SB)
	{
		swap(src);
		if (inst == SA)
			ft_putstr_fd("sa\n", STDOUT_FILENO);
		else if (inst == SB)
			ft_putstr_fd("sb\n", STDOUT_FILENO);
	}
	else if (inst == SS)
	{
		swap(src);
		swap(dst);
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	}
	else if (inst == PA || inst == PB)
	{
		push(src, dst);
		if (inst == PA)
			ft_putstr_fd("pa\n", STDOUT_FILENO);
		else if (inst == PB)
			ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
	else
		exec_inst2(src, dst, inst);
}
