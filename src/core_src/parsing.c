/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:26:59 by jonny             #+#    #+#             */
/*   Updated: 2021/06/23 20:11:39 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

/*
** Command Line parsing.
** Remove argv[0] and split argv[1] if one arg only.
** Returns a new array of strings.
*/
char	**parse_args(int argc, char **argv)
{
	int		i;
	char	**args;
	int		len;

	if (argc == 2)
		args = split_whitespace(argv[1]);
	else
	{
		len = 0;
		while (argv[len + 1])
			len++;
		args = ft_calloc(len + 1, sizeof(char *));
		i = 0;
		while (argv[i + 1])
		{
			args[i] = ft_strdup(argv[i + 1]);
			i++;
		}
	}
	return (args);
}
