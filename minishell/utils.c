/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:23:24 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/28 17:32:40 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	len1;
// 	size_t	len2;
// 	size_t	i;
// 	char	*dest;

// 	i = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	dest = (char *)malloc(len1 + len2 + 1);
// 	if (!dest)
// 		return (NULL);
// 	while (i < len1)
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	ft_strlcat(dest, s2, len1 + len2 + 1);
// 	return (dest);
// }

// void	free_all(char **dptr)
// {
// 	int	i;

// 	if (!dptr)
// 		return ;
// 	i = 0;
// 	while (dptr[i])
// 	{
// 		free(dptr[i]);
// 		i++;
// 	}
// 	free(dptr);
// }

// char	*ft_getpath(char *cmd, char **env)
// {
// 	char	**paths;
// 	char	*half_path;
// 	char	*path;
// 	int		i;

// 	i = 0;
// 	while (ft_strnstr(env[i], "PATH", 4) == 0)
// 		i++;
// 	paths = ft_split(env[i] + 5, ':');
// 	i = 0;
// 	while (paths[i])
// 	{
// 		half_path = ft_strjoin(paths[i], "/");
// 		path = ft_strjoin(half_path, cmd);
// 		free(half_path);
// 		if (access(path, F_OK | X_OK) == 0)
// 		{
// 			free_all(paths);
// 			return (path);
// 		}
// 		free(path);
// 		i++;
// 	}
// 	free_all(paths);
// 	return (0);
// }