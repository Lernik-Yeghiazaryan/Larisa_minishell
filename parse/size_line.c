/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:38:56 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:38:58 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_infile_count(char *line)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (line && line[++i])
	{
		if (line[i] == '<' && line[i + 1] == '<')
			while (line[i] == '<')
				++i;
		if (line[i] == '<' && line[i + 1] != '<')
			++count;
	}
	return (count);
}

int	ft_outfile_count(char *line)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (line && line[++i])
	{
		if (line[i] == '>' && line[i + 1] == '>')
			while (line[i] == '>')
				++i;
		if (line[i] == '>' && line[i + 1] != '>')
			++count;
	}
	return (count);
}

int	ft_heredoc_count(char *line)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!line)
		return (0);
	while (line && line[i])
	{
		if (line[i] == '<' && line[i + 1] && line[i + 1] == '<')
			++count;
		while (line[i] && line[i] == '<')
			++i;
		if (line[i])
			i++;
	}
	return (count);
}

int	ft_append_count(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line && line[i])
	{
		if (line[i] == '>' && line[i + 1] && line[i + 1] == '>')
			++count;
		while (line && line[i] && line[i] == '>')
			++i;
		if (line[i])
			++i;
	}
	return (count);
}
