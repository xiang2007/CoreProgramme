/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:46:04 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/29 16:02:05 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_data
{
	char	**env;

}				t_data;

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_getpath(char *cmd, char **env);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *find, const char *to_find, size_t len);

#endif