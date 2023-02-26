/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:05:34 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/25 12:19:53 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid(char *key, t_env **en)
{
	int	i;

	i = 0;
	if (!key)
		return (2);
	while (key[i])
	{
		if (!check_valid(key[i]) || (key[0] > 47 && key[0] < 58))
		{
			printf("unset: `%s': not a valid identifier\n", key);
			set_exit_code("1", en);
			return (1);
		}
		i++;
	}
	return (0);
}

void	cmd_unset(char *del_env, t_env **env)
{
	t_env	*curr;
	t_env	*delet;

	curr = (*env);
	if (is_valid(del_env, env))
		return ;
	while (curr->next)
	{
		if (!ft_strcmp(curr->next->key, del_env))
		{
			delet = curr->next;
			if (!curr->next->next)
				curr->next = NULL;
			else
				curr->next = curr->next->next;
			free(delet->value);
			free(delet->key);
			free(delet);
		}
		if (curr->next)
		curr = curr->next;
	}
}
