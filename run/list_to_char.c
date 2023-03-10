/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:35:12 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:35:15 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lst_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**list_to_char(t_env *env)
{
	int		i;
	char	**res;
	char	*tmp;

	i = 0;
	tmp = NULL;
	res = malloc(sizeof(char *) * (ft_lst_size(env) + 1));
	while (env)
	{
		if (env->key)
			res[i] = ft_strjoin(env->key, "=");
		if (env->value)
		{
			tmp = ft_strdup(res[i]);
			free(res[i]);
			res[i] = ft_strjoin(tmp, env->value);
			free(tmp);
			tmp = NULL;
		}
		i++;
		env = env->next;
	}
	res[i] = NULL;
	return (res);
}
