/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:28 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/20 16:18:09 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inint_env(char *elem1, char *elem2, t_env *node)
{
	node->key = ft_strdup(elem1);
	// printf("node->value = %s\n", node->value);
	if (node->value)
	{
		free(node->value);
		node->value = NULL;
	}
	node->value = ft_strdup(elem2);
	node->next = NULL;
}

void	environments(char **env, t_env **envir)
{
	int		i;
	char	**array;
	t_env	*new_node;

	i = 0;
	while (env[i])
	{
		new_node = malloc(sizeof(t_env));
		array = ft_split(env[i], '=');
		ft_inint_env(array[0], array[1], new_node);
		ft_lstadd_back_env(envir, new_node);
		++i;
		free_arr(array);
		array = NULL;
	}
}
