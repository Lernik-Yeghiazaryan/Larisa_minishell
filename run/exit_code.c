/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:31:44 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/10 17:31:45 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_code(t_env **en)
{
	t_env		*curr;
	long long	res;

	curr = *en;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "?"))
		{
			res = ft_atoi(curr->value);
			return (res);
		}
		curr = curr->next;
	}
	return (-1);
}

void	set_exit_code(char *value, t_env **en)
{
	t_env	*new_node;
	t_env	*curr;
	int		flag;

	flag = 0;
	curr = *en;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "?"))
		{
			free(curr->value);
			curr->value = ft_strdup(value);
			flag = 1;
		}
		curr = curr->next;
	}
	if (!flag)
	{
		new_node = malloc(sizeof(t_env));
		ft_inint_env("?", value, new_node);
		ft_lstadd_back_env(en, new_node);
	}
}
