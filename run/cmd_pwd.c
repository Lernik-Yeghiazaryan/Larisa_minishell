/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:06:10 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/20 16:08:02 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_pwd(t_env **en)
{
	char	cwd[256];
	char	*path;

	path = NULL;
	if (!(getcwd(cwd, sizeof(cwd))))
	{
		set_exit_code("1", en);
		perror("minishell: ");
		return (-1);
	}
	else
	{
		path = get_current_path();
		printf("%s\n", path);
		free(path);
	}
	return (0);
}
