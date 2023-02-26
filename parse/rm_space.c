/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:02:14 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/17 16:50:38 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "minishell.h"

char	*rm_space(char *str)
{
	int		i;
	int		d;
	char	*dst;

	i = 0;
	d = 0;
	dst = malloc((ft_strlen(str)) + 1);
	while (str[i])
	{
		while (str[i] == ' ')
			++i;
		if (str[i] == '\"')
			while (str[i] != '\"')
				dst[d++] = str[i++];
		else if (str[i] == '\'')
			while (str[++i] != '\'')
				dst[d++] = str[i++];
		dst[d++] = str[i++];
	}
	dst[d] = '\0';
	return (dst);
}
*/