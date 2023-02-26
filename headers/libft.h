/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:08:38 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/09 18:08:41 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int			ft_strlen(char *s);
int			ft_strcmp(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);
char		*ft_strcpy(char *dst, char *src);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlcpy(char *dst, char *src, int l);
char		*ft_strnstr(char *str, char *to_find, int len);
int			ft_isdigit(char c);
char		*ft_itoa(int n);
void		*ft_calloc(size_t c, size_t s);
int			ft_wcount(char *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strpaste(char *dst, char *src);
char		*ft_strdup(char *s1);
char		*ft_strtrim(char *s1, char *set, int *f);
char		**ft_split(char *s, char c);
char		**ft_split_pars(char *s, char c);
char		**ft_split_export(char *s, char c);
long long	ft_atoi(char *str);

#endif
