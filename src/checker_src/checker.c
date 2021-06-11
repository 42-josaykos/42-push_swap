/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:28:05 by jonny             #+#    #+#             */
/*   Updated: 2021/06/11 19:25:58 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	get_instructions(char **input)
{
	int		ret;
	char	buf[BUF_SIZE];
	char	tmp[BUF_SIZE];

	ret = 1;
	ft_bzero(buf, BUF_SIZE);
	ft_bzero(tmp, BUF_SIZE);
	while (ret)
	{
		ret = read(STDIN_FILENO, buf, BUF_SIZE);
		if (buf[0] == '\n')
			break ;
		ft_strcat(tmp, buf);
		ft_bzero(buf, BUF_SIZE);
	}
	*input = ft_calloc(ft_strlen(tmp) + 1, sizeof(char));
	ft_strlcpy(*input, tmp, ft_strlen(tmp) + 1);
	return (ret);
}

static bool	is_instruction(char *str)
{
	int			i;
	static char	*inst[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
							"rb", "rr", "rra", "rrb", "rrr"};

	i = 0;
	while (inst[i])
	{
		if (!ft_strncmp(str, inst[i], ft_strlen(str)))
			return (true);
		i++;
	}
	return (false);
}

int	check_instructions(char *input)
{
	char		**tmp;
	int			i;

	tmp = ft_split(input, '\n');
	i = 0;
	while (tmp[i])
	{
		if (!is_instruction(tmp[i]))
		{
			ft_putstr_fd(tmp[i], STDERR_FILENO);
			ft_putendl_fd(" is not a valid instruction", STDERR_FILENO);
			free_2darray(tmp);
			return (1);
		}
		i++;
	}
	free_2darray(tmp);
	return (0);
}

void	checker(t_lst *stack_a, char *inst)
{
	t_lst	*stack_b;
	int		nb_inst;

	init_stack(&stack_b, NULL);
	exec_instructions(stack_a, stack_b, inst);
	nb_inst = get_nb_inst(inst);
	if (!stack_b->len && is_sorted(stack_a, ASCENDING))
	{
		ft_putendl_fd("OK", STDOUT_FILENO);
		ft_putstr_fd("Instructions = ", STDOUT_FILENO);
		ft_putnbr_fd(nb_inst, STDOUT_FILENO);
		write(1, "\n", 1);
	}
	else
		ft_putendl_fd("KO", STDERR_FILENO);
	free_stack(stack_b);
}
