/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:18:33 by jonny             #+#    #+#             */
/*   Updated: 2021/04/06 12:22:02 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

bool	has_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[j] && j < i)
		{
			if (ft_strncmp(args[i], args[j], ft_strlen(args[j]) + 1) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	check_duplicate(char **args)
{
	if (has_duplicate(args))
	{
		ft_putendl_fd("Error: Duplicate Argument", STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	check_int_max(char *str)
{
	long int	nb;

	nb = ft_atoi(str);
	if (nb > INT_MAX || nb < INT_MIN)
	{
		ft_putendl_fd("Error: Int [-2147483648] [2147483647]", STDERR_FILENO);
		return (1);
	}
	return (0);
}

int	check_args_errors(char **args)
{
	int			i;
	long int	nb;

	i = 0;
	while (args[i])
	{
		if (!(*args[i]))
		{
			ft_putendl_fd("Error: Empty Argument", STDERR_FILENO);
			return (1);
		}
		else if (!is_number(args[i]))
		{
			ft_putendl_fd("Error: Invalid Argument", STDERR_FILENO);
			return (1);
		}
		else if (check_int_max(args[i]))
			return (1);
		i++;
	}
	if (check_duplicate(args))
		return (1);
	return (0);
}
