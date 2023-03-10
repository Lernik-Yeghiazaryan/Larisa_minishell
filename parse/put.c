/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:15:21 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/10 14:35:29 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	size_infile(char *str, int i, char c)
{
	if (str[i] == c)
	{
		i++;
		while (str[i] && (str[i] == c || is_space(str[i])))
			i++;
		while (str[i] && !is_meta(str[i]))
			i++;
	}
	return (i);
}

int	put_in_out(t_node *node, char c)
{
	int	i;
	int	l;
	int	start;
	int	s;

	i = 0;
	s = 0;
	start = 0;
	while (node->readline[start])
	{
		l = size_infile(node->readline, start, c) - start;
		if (node->readline[start] == c && node->readline[start + 1] != c
			&& ((start - 1 < 0) || ((start - 1) >= 0
					&& node->readline[start - 1] != c)))
		{
			if (c == '<')
				node->infile[i] = ft_substr(node->readline, start, l);
			else if (c == '>')
				node->outfile[i] = ft_substr(node->readline, start, l);
			s += l;
			i++;
		}
		start++;
	}
	return (s);
}

static int	size_heredoc(char *str, int i, char c)
{
	if (str[i] == c && str[i + 1] == c)
	{
		i += 2;
		while (str[i] == c)
			i++;
		while (str[i] && is_space(str[i]))
			i++;
		while (str[i] && !is_meta(str[i]))
			i++;
	}
	return (i);
}

int	put_hd_app(t_node *node, char c)
{
	int	i;
	int	l;
	int	start;
	int	s;

	i = 0;
	s = 0;
	start = 0;
	while (node->readline[start])
	{
		l = size_heredoc(node->readline, start, c) - start;
		if (node->readline[start] == c && node->readline[start + 1] == c)
		{
			if (c == '<')
				node->heredoc[i] = ft_substr(node->readline, start, l);
			else if (c == '>')
				node->append[i] = ft_substr(node->readline, start, l);
			s += l;
			i++;
			while (node->readline[start + 2] == c)
				++start;
		}
		start++;
	}
	return (s);
}
