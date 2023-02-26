/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:08:52 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:20:37 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*fr(char **s, int i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (0);
}

static char	*ml(char *s, int st, int len)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	while (s[st] && i < len)
	{
		tab[i] = s[st];
		st++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split_export(char *s, char c)
{
	char	**tab;
	int		start;

	start = -1;
	tab = malloc(sizeof(char **) * 3);
	if (!(tab) || !s)
		return (0);
	while (s[++start])
	{	
		if (s[start] && s[start] == c)
		{
			tab[0] = ml(s, 0, start);
			if (s[start + 1])
			{
				tab[1] = ml(s, start + 1, ft_strlen(s) - start - 1);
				tab[2] = 0;
			}
			else
				tab[1] = 0;
			return (tab);
		}
	}
	if (!tab)
		fr(tab, start);
	return (tab);
}
