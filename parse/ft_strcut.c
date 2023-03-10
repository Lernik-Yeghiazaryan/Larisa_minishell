/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:38:13 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/10 15:07:44 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_find(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (0);
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (!(to_find[j + 1]))
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strcut(char *readline, char *str)
{
	int		i;
	int		k;
	int		find;
	char	*cmdline;

	i = -1;
	k = 0;
	find = ft_find(readline, str);
	if (!find || !readline || !str)
		return (0);
	cmdline = ft_calloc(sizeof(char),
			(ft_strlen(readline) - ft_strlen(str)) + 1);
	while (++i < find && readline[i])
		cmdline[i] = readline[i];
	k = i + ft_strlen(str);
	while (readline[k] && i < ft_strlen(readline) - ft_strlen(str))
	{
		cmdline[i] = readline[k];
		i++;
		k++;
	}
	cmdline[i] = '\0';
	free(readline);
	return (cmdline);
}	
