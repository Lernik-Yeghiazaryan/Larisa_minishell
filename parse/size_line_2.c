/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_line_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:24:23 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 18:24:26 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_all_redir_size(t_node *node)
{
	int	res;

	res = 0;
	res += node->counts.s_append;
	res += node->counts.s_heredoc;
	res += node->counts.s_infile;
	res += node->counts.s_outfile;
	return (res);
}

// int	ft_size_all(char *str)
// {
// 	int	i;
// 	int	count;
// 	int	f1;
// 	int	f2;
// 	int	f3;

// 	i = 0;
// 	f1 = 0;
// 	f2 = 0;
// 	f3 = 0;
// 	count = 0;
// 	while (str && str[i])
// 	{
// 		ignore_quotes(str);
// 		while (!is_meta(str[i]) && i++)
// 			f1 = 1;
// 		while (str && str[i] == '<' && i++)
// 			f2 = 1;
// 		while (str && str[i] == '>' && i++)
// 			f3 = 1;
// 		while (str && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
// 		{
// 			if ((f1 == 1 && count++ && (f1 = 0))
// 				|| (f2 == 1 && count++ && (f2 = 0))
// 				|| (f3 == 1 && count++ && (f3 = 0)))
// 				;
// 			i++;
// 		}
// 			i++;
// 	}
// 	return (count);
// }