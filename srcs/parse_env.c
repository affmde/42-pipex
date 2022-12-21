/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:30 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/21 12:35:55 by andrferr         ###   ########.fr       */
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
	while (pipex->possible_paths[i])
	{
		pipex->possible_paths[i] = add_slash(pipex->possible_paths[i]);
		i++;
	}
}

void	parse_env(t_pipex *pipex, char **env, int cmd)
{
	pipex->path = find_path(env);
	pipex->possible_paths = ft_split(pipex->path, ':');
	update_paths(pipex);
	if (cmd == 1)
		pipex->args = ft_split(pipex->cmd1, ' ');
	else if (cmd == 2)
		pipex->args = ft_split(pipex->cmd2, ' ');
}
