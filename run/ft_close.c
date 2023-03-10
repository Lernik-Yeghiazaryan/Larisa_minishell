/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:09:33 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/10 18:09:35 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close(int (*fd)[2], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	add_env(char **array, t_env **en)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	ft_inint_env(array[0], array[1], new_node);
	ft_lstadd_back_env(en, new_node);
}
