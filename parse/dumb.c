/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:56:10 by tyenokya          #+#    #+#             */
/*   Updated: 2023/03/10 15:29:29 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dumb(t_env **en)
{
	ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
	set_exit_code("258", en);
	return (1);
}
