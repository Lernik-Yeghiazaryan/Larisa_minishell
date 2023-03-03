/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:08:50 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 17:24:15 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_size
{
	int			s_infile;
	int			s_outfile;
	int			s_heredoc;
	int			s_append;
	int			s_pipe;
	int			s_cmd;
	int			s_all;
}				t_size;

typedef struct s_node
{
	t_size			counts;
	char			*readline;
	char			**heredoc;
	char			**append;
	char			**infile;
	char			**outfile;
	char			**cmd;
	struct s_node	*next;
	int				inf_err_code;
	int				inf_stat;
	int				pid;
}					t_node;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

# define BLACK		 "\033[0;30m"
# define BOLD_BLACK  "\033[1;30m"
# define RED		 "\033[0;31m"
# define BOLD_RED	 "\033[1;31m"
# define GREEN 		 "\033[0;32m"
# define BOLD_GREEN  "\033[1;32m"
# define YELLOW 	 "\033[0;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE 		 "\033[0;34m"
# define BOLD_BLUE 	 "\033[1;34m"
# define PURPLE 	 "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define CYAN 		 "\033[0;36m"
# define BOLD_CYAN   "\033[1;36m"
# define WHITE 		 "\033[0;37m"
# define BOLD_WHITE  "\033[1;37m"
# define RESET_COLOR "\033[0m"
# define ESC_BLACK		 "\001\033[0;30m"
# define ESC_BOLD_BLACK  "\001\033[1;30m\002"
# define ESC_RED 		 "\001\033[0;31m\002"
# define ESC_BOLD_RED 	 "\001\033[1;31m\002"
# define ESC_GREEN 		 "\001\033[0;32m\002"
# define ESC_BOLD_GREEN  "\001\033[1;32m\002"
# define ESC_YELLOW 	 "\001\033[0;33m\002"
# define ESC_BOLD_YELLOW "\001\033[1;33m\002"
# define ESC_BLUE 		 "\001\033[0;34m\002"
# define ESC_BOLD_BLUE   "\001\033[1;34m\002"
# define ESC_PURPLE 	 "\001\033[0;35m\002"
# define ESC_BOLD_PURPLE "\001\033[1;35m\002"
# define ESC_CYAN 		 "\001\033[0;36m\002"
# define ESC_BOLD_CYAN   "\001\033[1;36m\002"
# define ESC_WHITE 		 "\001\033[0;37m\002"
# define ESC_BOLD_WHITE  "\001\033[1;37m\002"
# define ESC_RESET_COLOR "\001\033[0m\002"
# define METACHARACTERS  "|&;()<> \n\t"
# define SPACES  " \n\t"

#endif