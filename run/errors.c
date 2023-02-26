/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:08:19 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/08 17:18:42 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_env **en)
{
	delete_list(en);
	exit(0);
}

void	ft_print_exit(void)
{
	printf("minishell :exit");
	exit(0);
}
