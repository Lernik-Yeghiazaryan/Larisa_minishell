/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:42:54 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/08 17:18:10 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_infile(char *file, int flag)
{
	int	fd;

	fd = open(++file, O_RDONLY, 0644);
	if (fd < 0)
		perror("minishell : no such file or directori");
	if (!flag)
		dup2(fd, 0);
	close(fd);
}

void	cmd_outfile(char *file, int flag)
{
	int	fd;

	fd = open(++file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (flag == 1)
		dup2(fd, 1);
	close(fd);
}

void	cmd_append(char *file, int flag)
{
	int	fd;

	fd = open(file + 2, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (flag == 1)
		dup2(fd, 1);
	close(fd);
}
