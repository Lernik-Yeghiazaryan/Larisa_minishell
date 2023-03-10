/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:33:18 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/10 14:15:19 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_clean(char **str, t_env **envir)
{
	int	i;
	int	f;
	int	t;

	i = 0;
	f = 0;
	t = 0;
	while (str && str[i])
	{
		str[i] = ft_strtrim(str[i], SPACES, &f);
		str[i] = ft_strtrim(str[i], "\'", &t);
		if (t)
		{
			++i;
			continue ;
		}
		str[i] = ft_strtrim(str[i], "\"", &f);
		str[i] = change_doll(str[i], envir);
		i++;
	}
	return (str);
}

void	ft_clean_spasec(t_node *head, t_env **envir)
{
	t_node	*node;

	node = head;
	if (node->cmd)
		node->cmd = ft_clean(node->cmd, envir);
	if (node->infile[0])
		node->infile = ft_clean(node->infile, envir);
	if (node->outfile[0])
		node->outfile = ft_clean(node->outfile, envir);
	if (node->append[0])
		node->append = ft_clean(node->append, envir);
	if (node->heredoc[0])
		node->heredoc = ft_clean(node->heredoc, envir);
}

char	*ft_clean_spase_between(char *str)
{
	int		i;
	char	*res;
	char	*res_temp;
	char	*temp;
	int		start;

	i = -1;
	start = 0;
	temp = NULL;
	res = NULL;
	while (str && str[++i])
	{
		start = i;
		while (str[i] && is_space(str[i]))
			i++;
		res_temp = ft_substr(str, 0, start);
		temp = ft_substr(str, i, ft_strlen(str) - i);
		res = ft_strjoin(res_temp, temp);
		if (res && str[i] && str[i + 1])
			free(res);
		free(temp);
		free(res_temp);
	}
	return (res);
}

void	ft_clean_red(t_node *node)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (node->outfile && node->outfile[i])
	{
		tmp = ft_strdup(node->outfile[i]);
		free(node->outfile[i]);
		node->outfile[i] = 0;
		node->outfile[i] = ft_clean_spase_between(tmp);
		free(tmp);
		tmp = NULL;
		i++;
	}
}
