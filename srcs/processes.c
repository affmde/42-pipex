/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:21:51 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/20 14:59:30 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_command(char **paths, char *cmd)
{
	char *tmp;

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
	char *cmd;

	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->fd[0]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	parse_env(pipex, env, 1);
	cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!cmd)
	{
		close(pipex->fd[1]);
		return (0);
	}
	execve(cmd, pipex->args, env);
	close(pipex->fd[0]);
	return (1);
}

int	handle_parent(t_pipex *pipex, char **env)
{
	char *cmd;

	waitpid(pipex->pid, NULL, 0);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[1]);
	dup2(pipex->outfile, STDOUT_FILENO);
	parse_env(pipex, env, 2);
	cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!cmd)
	{
		return (0);
	}
	close(pipex->fd[1]);
	return (1);
}
