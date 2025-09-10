/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:25:45 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/09/10 19:45:15 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_data
{
	char	*p1;
	char	*p2;
	char	**cmd1;
	char	**cmd2;
	char	*error_cmd;
}				t_data;

typedef struct s_file
{
	int	file1;
	int	file2;
}				t_file;


char	*getpath(char *cmd, char **env);
void	error(int value);
void	child_ps(int *fd, char **av, char **env);
void	parent_ps(int *fd, char **av, char **env);
void	execute(char *av, char **env);
void	free_all(char **dptr);
int		check_path(char *path);
void	check_cmd(char *cmd);
void	child_ps_2(int *fd, char **av, char **env);
char	*ft_getpath(char *cmd, char **env);

#endif
