/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:10:34 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:10:36 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	kill_proces(int child, int i)
{
	while (i > -1)
	{
		kill(child, SIGKILL);
		waitpid(child, NULL, WUNTRACED);
		i--;
	}
	ft_putstr_fd("minishell: fork error\n", 2);
}

void	child_error(int child, int i)
{
	kill_proces(child, i);
	perror("minishell: fork ");
	exit(1);
}
