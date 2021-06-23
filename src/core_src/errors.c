/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:18:33 by jonny             #+#    #+#             */
/*   Updated: 2021/06/23 20:14:44 by jonny            ###   ########.fr       */
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
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
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
		ft_putendl_fd("Error", STDERR_FILENO);
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
		ft_putendl_fd("Error", STDERR_FILENO);
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
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
		else if (!is_number(args[i]))
		{
			ft_putendl_fd("Error", STDERR_FILENO);
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
