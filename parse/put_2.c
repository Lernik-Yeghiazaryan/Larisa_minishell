/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:18:26 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/19 12:53:20 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static	void	*pars_ft_memchr(void *s, int c, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((unsigned char *)s) + i);
		i++;
	}
	return (NULL);
}

static char	*pars_ft_strchr(char *s, int c)
{
	return (pars_ft_memchr(s, c, ft_strlen(s) + 1));
}

int	is_meta(char c)
{
	if (c == '\0')
		return (0);
	if (pars_ft_strchr(METACHARACTERS, c))
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (ft_strchr(SPACES, c) != 0)
		return (1);
	return (0);
}
