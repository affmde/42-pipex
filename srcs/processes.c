/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:21:51 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/27 21:17:24 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_command(char **paths, char *cmd)
{
	char	*tmp;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, cmd);
		if (!tmp)
			return (NULL);
		if (access(tmp, 0) == 0)
			return (tmp);
		free(tmp);
		paths++;
	}
	return (NULL);
}

int	process_one(t_pipex *pipex, char **env)
{
	close(pipex->fd[0]);
	if (dup2(pipex->fd[1], STDOUT_FILENO) < 0)
		return (0);
	if (dup2(pipex->infile, STDIN_FILENO) < 0)
		return (0);
	pipex->args = ft_split(pipex->cmd1, ' ');
	if (!pipex->args)
		return (0);
	pipex->path_cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!pipex->path_cmd)
	{
		error_msg(pipex->cmd1);
		clean_pipex(pipex);
		exit (EXIT_FAILURE);
	}
	close(pipex->fd[1]);
	if (execve(pipex->path_cmd, pipex->args, env) < 0)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	process_two(t_pipex *pipex, char **env)
{
	close(pipex->fd[1]);
	if (dup2(pipex->fd[0], STDIN_FILENO) < 0)
		return (0);
	if (dup2(pipex->outfile, STDOUT_FILENO) < 0)
		return (0);
	pipex->args = ft_split(pipex->cmd2, ' ');
	if (!pipex->args)
		return (0);
	pipex->path_cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!pipex->path_cmd)
	{
		clean_pipex(pipex);
		error_msg(pipex->cmd2);
		exit (EXIT_FAILURE);
	}
	close(pipex->fd[0]);
	if (execve(pipex->path_cmd, pipex->args, env) < 0)
	{
		clean_pipex(pipex);
		return (0);
	}
	return (EXIT_FAILURE);
}
