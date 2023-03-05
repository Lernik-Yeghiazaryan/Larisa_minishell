/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:02:06 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/22 16:37:04 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid_identif(char *str, t_env **en)
{
	int		i;
	char	**array;

	i = 0;
	if (ft_strnstr(str, "+=", ft_strlen(str)))
	{
		array = ft_split(str, '+');
		++i;
	}
	else
		array = ft_split(str, '=');
	if (!array[0])
	{
		// free_arr(array);
		return (0);
	}
	i = 0;
	while (array[0] && array[0][i])
	{
		if (!check_valid(array[0][i]))
		{
			set_exit_code("1", en);
			free_arr(array);
			return (0);
		}
		i++;
	}
	free_arr(array);
	return (1);
}

int	check_pluse_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && str[i + 1] != '=')
			return (0);
		i++;
	}
	return (1);
}

void	pluse_equal_2(char *cmd, t_env **en)
{
	char **array;
	char **array0;

	if (!check_pluse_equal(cmd))
	{
		printf("export: `%s': not a valid identifier\n", cmd);
		set_exit_code("1", en);
		return ;
	}
	array = ft_split_export(cmd, '+');
	array0 = malloc(sizeof(char *) * 3);
	array0[0] = ft_strdup(array[0]);
	array0[1] = ft_strdup(array[1] + 1);
	array0[2] = 0;
	free_arr(array);
	pluse_equal(array0, en);
	free_arr(array0);
}
