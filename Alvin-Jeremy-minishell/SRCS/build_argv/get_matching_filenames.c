/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matching_filenames.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:43:21 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/23 22:22:13 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

static int	ft_strcmp_wrapper(const void *ptr1, const void *ptr2)
{
	const char	*str1 = *(const char **)ptr1;
	const char	*str2 = *(const char **)ptr2;
	int			i;

	i = 0;
	while (str1[i] && str2[i] && ft_toupper(str1[i]) == ft_toupper(str2[i]))
		i++;
	if (!str1[i] && !str2[i])
	{
		i = 0;
		while (str1[i] == str2[i])
			i++;
		return (str2[i] - str1[i]);
	}
	if (ft_isalnum(str1[i]) && !ft_isalnum(str2[i]))
		return (1);
	else if (!ft_isalnum(str1[i]) && ft_isalnum(str2[i]))
		return (-1);
	if (ft_isalpha(str1[i]) && ft_isalpha(str2[i]))
		return (ft_toupper(str1[i]) - ft_toupper(str2[i]));
	return (str1[i] - str2[i]);
}

static int	count_files(void)
{
	DIR				*dir;
	struct dirent	*dirent;
	int				count;

	count = 0;
	dir = opendir(".");
	if (!dir)
		return (0);
	dirent = readdir(dir);
	while (dirent)
	{
		count++;
		dirent = readdir(dir);
	}
	closedir(dir);
	return (count);
}

static char	**get_all_filenames(void)
{
	DIR				*dir;
	struct dirent	*dirent;
	int				i;
	char			**filenames;

	dir = opendir(".");
	if (!dir)
		return (NULL);
	filenames = (char **)malloc((count_files() + 1) * sizeof(char *));
	i = 0;
	dirent = readdir(dir);
	while (dirent)
	{
		filenames[i] = ft_strdup(dirent->d_name);
		if (!filenames[i++])
		{
			ft_strarr_free(filenames);
			closedir(dir);
			return (NULL);
		}
		dirent = readdir(dir);
	}
	filenames[i] = NULL;
	closedir(dir);
	return (filenames);
}

static void	filter_filenames(t_list *wildcard, char **filenames)
{
	int	i;

	while (*filenames)
	{
		if (!match_wildcard(wildcard, *filenames))
		{
			free(*filenames);
			i = 0;
			while (filenames[i])
			{
				filenames[i] = filenames[i + 1];
				i++;
			}
		}
		else
			filenames++;
	}
}

char	**get_matching_filenames(t_list *wildcard)
{
	char	**filenames;
	size_t	filenames_len;

	filenames = get_all_filenames();
	if (!filenames)
		return (NULL);
	filter_filenames(wildcard, filenames);
	if (!*filenames)
	{
		free(filenames);
		return (NULL);
	}
	filenames_len = ft_strarr_len(filenames);
	ft_qsort(filenames, filenames_len, sizeof(char *), ft_strcmp_wrapper);
	return (filenames);
}
