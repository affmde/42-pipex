/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:21:51 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/22 10:24:22 by andrferr         ###   ########.fr       */
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

int	handle_child(t_pipex *pipex, char **env)
{
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[0]);
	dup2(pipex->infile, STDIN_FILENO);
	pipex->args = ft_split(pipex->cmd1, ' ');
	pipex->path_cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!pipex->path_cmd)
	{
		error_msg(pipex->cmd1);
		clean_pipex(pipex);
		exit (127);
	}
	close(pipex->fd[1]);
	if (execve(pipex->path_cmd, pipex->args, env) < 0)
		return (0);
	return (1);
}

int	handle_parent(t_pipex *pipex, char **env)
{
	int	status;
	
	waitpid(pipex->pid, &status, 0);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[1]);
	dup2(pipex->outfile, STDOUT_FILENO);
	pipex->args = ft_split(pipex->cmd2, ' ');
	pipex->path_cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!pipex->path_cmd)
	{
		clean_pipex(pipex);
		error_msg(pipex->cmd2);
		exit (127);
	}
	close(pipex->fd[0]);
	if (execve(pipex->path_cmd, pipex->args, env) < 0)
	{
		clean_pipex(pipex);
		return (0);
	}
	return (1);
}
