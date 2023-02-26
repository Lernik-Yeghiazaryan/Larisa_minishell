/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:20:48 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 17:34:15 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_env **node)
{
	t_env	*curr;

	curr = (*node);
	while (curr)
	{
		if (curr->value)
		{
			if (ft_strcmp(curr->key, "?") != 0)
			{
				printf("%s", curr->key);
				printf("=%s\n", curr->value);
			}
		}
		curr = curr->next;
	}
}

static void	print_list_added(t_env **node)
{
	t_env	*curr;

	curr = (*node);
	while (curr)
	{
		if (ft_strcmp(curr->key, "?") != 0)
		{	
			printf("declare -x %s", curr->key);
			if (curr->value)
				printf("=\"%s\"\n", curr->value);
			else
				printf("\n");
		}
		curr = curr->next;
	}
}

void	sort_list(t_env **env)
{
	t_env	*current;
	t_env	*index;
	char	*temp;

	index = NULL;
	current = *env;
	if (env == NULL)
		return ;
	while (!current)
	{
		index = current->next;
		while (index != NULL)
		{
			if (ft_strcmp(current->key, index->key) > 0)
			{
				temp = current->key;
				current->key = index->key;
				index->key = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
	print_list_added(env);
}
