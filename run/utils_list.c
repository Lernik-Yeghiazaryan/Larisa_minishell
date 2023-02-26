/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:51:45 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:36:31 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_list(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			return (env->value);
		}
		env = env->next;
	}
	return (0);
}

void	delete_list(t_env **env)
{
	t_env	*tmp;

	while (*env)
	{
		tmp = (*env);
		(*env) = (*env)->next;
		free(tmp);
	}
	return ;
}

static t_env	*ft_lstlast_env(t_env *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*back;

	back = *lst;
	if (!(lst))
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		back = ft_lstlast_env(*lst);
		back->next = new;
	}
}

int	node_len(t_node *node)
{
	int	res;

	res = 0;
	while (node)
	{
		node = node->next;
		res++;
	}
	return (res);
}
