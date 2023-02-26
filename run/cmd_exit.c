/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:59:01 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:34:27 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_normal(char **cmd, t_env **en)
{
	long long	dig;
	long long	code;

	dig = ft_atoi(cmd[1]);
	code = get_exit_code(en);
	if (dig < 0)
	{
		ft_putstr_fd("exit\n", 2);
		code = 256 - (dig * (-1)) % 256;
		exit(code);
	}
	else
	{
		ft_putstr_fd("exit\n", 2);
		code = dig % 256;
		exit(code);
	}
}

void	cmd_exit(char **cmd, t_env **en)
{
	if (!cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		exit(get_exit_code(en));
	}
	if (cmd[1] && (!(ft_isdigit(cmd[1][0]) || cmd[1][0] == '-')
		|| (ft_strlen(cmd[1]) == 19 && (cmd[1][ft_strlen(cmd[1]) - 1] == '8'
		|| cmd[1][ft_strlen(cmd[1]) - 1] == '9'))))
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: :exit: numeric argument required\n", 2);
		set_exit_code("255", en);
		exit(get_exit_code(en));
	}
	if (cmd[2])
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: :exit: too many arguments: \n", 2);
		set_exit_code("1", en);
		return ;
	}
	exit_normal(cmd, en);
}
