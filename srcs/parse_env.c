/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:30 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/28 11:28:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH", env[i], ft_strlen("PATH")))
			return (ft_substr(env[i], 5, ft_strlen(env[i]) - 5));
		i++;
	}
	return (NULL);
}

static char	*add_slash(char *arr)
{
	char	*tmp;

	tmp = ft_strjoin(arr, "/");
	if (!tmp)
		return (NULL);
	free(arr);
	return (tmp);
}

static void	update_paths(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->possible_paths[i])
	{
		while (pipex->possible_paths[i])
		{
			pipex->possible_paths[i] = add_slash(pipex->possible_paths[i]);
			i++;
		}
	}
}

int	parse_env(t_pipex *pipex, char **env)
{
	pipex->path = find_path(env);
	if (!pipex->path)
	{
		close(pipex->infile);
		close(pipex->outfile);
		return (0);
	}
	pipex->possible_paths = ft_split(pipex->path, ':');
	update_paths(pipex);
	return (1);
}
