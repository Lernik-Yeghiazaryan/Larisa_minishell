/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:46:50 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/24 17:11:59 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_s;

	new_s = (char *)s;
	while (*new_s != '\0')
	{
		if (*new_s == c)
			return (new_s);
		new_s++;
	}
	if (*new_s == '\0' && c == '\0')
		return (new_s);
	return (0);
}

char	ft_strgtav(char *str, int c)
{
	int		i;
	char	sym;

	i = 0;
	sym = c;
	while (str[i] && str[i] != sym)
		i++;
	if (str[i] == sym)
		return (' ');
	return ('\0');
}
