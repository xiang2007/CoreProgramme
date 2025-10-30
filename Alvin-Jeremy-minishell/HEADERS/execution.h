/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:13:04 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/28 02:17:16 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "env_vars.h"
# include "ast.h"
# include "minishell.h"

# define FD_MAX		1024

# define ERMALLOC	255
# define ERDUP		254
# define ERPIPE		253
# define ERFORK		252
# define ERFATAL	-1

typedef struct s_shelldata	t_shelldata;
typedef t_pipe				t_pipelst;

typedef struct s_pipes
{
	int	(*fds)[2];
	int	count;
}	t_pipes;

//executions
int		execute_ast(t_ast *ast, t_shelldata *shelldata);
int		simple_execute(t_simple *simple, t_shelldata *shelldata);
char	**build_argv(char **strarr, t_list *env_vars);
int		binary_execute(char **argv, t_shelldata *shelldata);
int		andor_execute(t_andor *andor, t_shelldata *shelldata);
int		subshell_execute(t_subshell *subshell, t_shelldata *shelldata);
int		pipe_execute(t_pipe *pipe_node, t_shelldata *shelldata);

//binary_execute_utils
int		is_file(char *path);
char	*path_join(char *path_option, char *cmd);
char	**create_envp(t_list **env_vars, char *bin_path);
int		clean_execve(char *bin_path, char *argv[], char *envp[],
			t_shelldata *shelldata);

//pipe_utils
int		count_pipes(t_pipelst *pipe);
int		open_pipes(t_pipes *pipes);
void	close_pipes(t_pipes *pipes);
int		wait_and_return(pid_t pid);

//redirections
void	close_heredocs(int heredoc_fds[FD_MAX]);
char	*get_eof(char *word);
int		save_io_fds(int io_fds[2]);
int		restore_io_fds(int io_fds[2]);
int		process_redirection(t_redir *redir, t_shelldata *shelldata);
void	expand_heredoc(t_redir *redir, t_shelldata *shelldata);

int		create_shell_child(t_shelldata *shelldata);
void	clean_exit(t_shelldata *shelldata, int exit_code);

#endif
