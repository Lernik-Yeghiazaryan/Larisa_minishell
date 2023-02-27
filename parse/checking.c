/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:17:24 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 15:06:03 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checkquotes(char *str)
{
	int	i;
	int	count[2];

	i = 0;
	count[0] = 0;
	count[1] = 0;
	while (str && str[i])
	{
		if (str[i] == '\"')
		{
			++count[0];
			while (str[++i] && str[i] != '\"')
				;
			if (str[i] == '\"')
			{
				++count[0];
			}
		}
		else if (str[i] == '\'')
		{
			++count[1];
			while (str[++i] && str[i] != '\'')
				;
			if (str[i] == '\'')
			{
				++count[1];
			}
		}
		if (!str || !str[i])
			break;
		++i;
	}
	if (count[0] % 2 || count[1] % 2)
		return (1);
	return (0);
}

int	check_quote_2(t_node *node, t_env **en)
{
	int		i;
	char	*curr;
	char	c;

	i = 0;
	curr = node->readline;
	while (curr[i])
	{
		if (curr[i] == '\'' || curr[i] == '"')
		{
			c = curr[i++];
			if (curr[i] == '\0')
			{
				ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
				set_exit_code("258", en);
				return (1);
			}
			while (curr[i] && curr[i] != c)
				i++;
			if (curr[i] != c)
			{
				ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
				set_exit_code("258", en);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static int	find_unexpected_token(char *s, int i, t_env **en)
{
	while (s[i] && ft_strchr(SPACES, s[i]))
		i++;
	if (s[i] == '\0' || ft_strchr("|&;()><", s[i]))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		set_exit_code("258", en);
		return (1);
	}
	return (0);
}

static int	check_redir(char *s, t_env	**en)
{
	int	i;

	i = -1;
	while (s[++i] && !ft_strchr("()|&;", s[i]))
	{
		if ((s[i] == '>' && s[i + 1] == '>' && ++i && ++i)
			|| (s[i] == '<' && s[i + 1] == '<' && ++i && ++i)
			|| (s[i] == '<' && ++i)
			|| (s[i] == '>' && ++i))
		{
			if (find_unexpected_token(s, i, en))
				return (1);
		}
	}
	return (0);
}

static int	unexp_symv(char *tmp, int i, t_env **en)
{
	//Larisa es incher es arel, AAAAAAAAAAA  echo "cat < a | > b"
	if (tmp[i] == '\0' || ft_strchr("|&;()", tmp[i]))
	{
		if (tmp[i] == '\0' || ft_strchr("|&;()", tmp[i]))
		{
			ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
			// printf("minishell: syntax error near unexpected token\n");//layisyaaaaaaa syntax errory write-ov kanes fd-n 2 ktas
			set_exit_code("258", en);
			return (1);
		}
	}
	return (0);
}

int	unexpected_tokens(t_node *node, t_env **en)
{
	char	*curr;
	int		i;

	i = 0;
	curr = node->readline;
	while (curr[i])
	{
		if (check_redir(curr + i, en))
			return (1);
		while (curr[i] && ft_strchr(SPACES, curr[i]))
			i++;
		ignore_quotes(node->readline, &i);
		if (!curr[i])
			return (0);
		if (curr[i] && ft_strchr("|&;()", curr[i]))
		{
			if (unexp_symv(curr, i, en))
				return (1);
		}
		if (curr[i] && !ft_strchr("|&;()", curr[i]))
			i++;
	}
	return (0);
}
