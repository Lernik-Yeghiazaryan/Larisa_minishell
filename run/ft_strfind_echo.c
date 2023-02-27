/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:23:13 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/18 17:42:23 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid(char c)
{
	if (c == '_' || (c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			printf("%c, aaaa\n", c);
			return (1);
		}
	printf("%c, aaaa\n", c);
	return (0);
}

void	var_values(char *str, t_env *en)
{
	while (en)
	{
		if (!ft_strcmp(en->key, str))
			printf("%s", en->value);
		en = en->next;
	}
}
