/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:44:17 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 18:22:50 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include "libft.h"
# include "structs.h"

int		checkquotes(char *str);
char	ft_strgtav(char *str, int c);
void	ft_lstadd_back(t_node **lst, t_node *new_env);
void	ft_lstadd_back_env(t_env **lst, t_env *new_env);
void	ft_inint_env(char *elem1, char *elem2, t_env *node);
int		builtin(t_node node, t_env **en);
int		is_builtin(char *cmd);
int		cmd_pwd(t_env **en);
int		print_exit_code(t_env **en);
int		cmd_cd(t_node node, t_env **en);
void	cmd_echo(t_node n, t_env **en);
void	cmd_export(t_node n, t_env **en);
void	cmd_exit(char **cmd, t_env **en);
void	cmd_unset(char *del_env, t_env **env);
void	print_list(t_env **node);
char	*search_list(t_env *env, char *key);
void	delete_list(t_env **env);
int		check_valid(char c);
int		check_valid_identif(char *str, t_env **en);
void	update_list_item(t_env **lst, char *key, char *value);
char	*get_current_path(void);
void	sort_list(t_env **env);
int		commands(t_node node, t_env **envir);
void	environments(char **env, t_env **envir);
char	**list_to_char(t_env *env);
void	lexer(t_node **node, char *str, t_env **en);
t_node	*parser(t_node *node, t_env **en);
int		node_len(t_node *node);
void	ft_pipe(t_node *node, t_env **envir);
void	print_node(t_node *node);
int		check_pluse_equal(char *str);
void	pluse_equal_2(char *cmd, t_env **en);
void	pluse_equal(char **array, t_env **en);
void	child_error(int child, int i);
int		ft_arrlen(char **str);
void	ft_free_str(char *cmd);
void	cmd_no_infile(char *file, t_node *node);
void	cmd_infile(char *file, t_node *node);
void	cmd_outfile(char *file, int flag);
void	cmd_append(char *file, int flag);
void	heredoc(char *str);
void	heredoc_not(char *str);
void	ft_print_hered(char *line, int fd);
void	ft_redirs(t_node *node);
void	handler(int sig);
void	ft_quit(int sig);
void	ft_print_exit(void);
t_node	*cut_redir(t_node *node);
char	*pars_ft_strjoin(char *s1, char *s2);
char	**pars_ft_split(char *s, char c);
int		put_in_out(t_node *node, char c);
int		put_hd_app(t_node *node, char c);
int		put_cmd(t_node *node, int i);
int 	initial_nodes(t_node *node);
int		ft_infile_count(char *line);
int		ft_outfile_count(char *line);
int		ft_heredoc_count(char *line);
int		ft_append_count(char *line);
int		ft_all_redir_size(t_node *node);
char	*ft_strcut(char *readline, char *str);
int		is_meta(char c);
int		is_space(char c);
void	ignore_quotes(char *str, int *i);
void	set_exit_code(char *value, t_env **en);
int		check_quote_2(t_node *node, t_env **en);
int		unexpected_tokens(t_node *node, t_env **en);
void	ft_list_add_back(t_node **lst, t_node *new);
char	**ft_clean(char **str, t_env **envir);
void	ft_clean_spasec(t_node *head, t_env **envir);
char	*ft_clean_spase_between(char *str);
void	ft_clean_sp_redir(t_node *node);
int		get_exit_code(t_env **en);
char	*change_doll(char *str, t_env **en);
int		ft_isalpha(int c);
void	ft_putstr_fd(char *s, int fd);
void	not_found_error(char *cmd, t_env **en);
void	ft_heredoc(t_node *node);
void	*free_arr(char **s);
int		command_for_pipe(t_node node, t_env **envir);
void	free_node(t_node *node);
void	free_one_node(t_node node);

#endif
