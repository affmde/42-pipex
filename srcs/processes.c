/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:21:51 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/21 12:34:24 by andrferr         ###   ########.fr       */
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
	char	*cmd;

	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->fd[0]);
	dup2(pipex->fd[1], STDOUT_FILENO);
	parse_env(pipex, env, 1);
	cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!cmd)
	{
		error(pipex->cmd1);
		clean_pipex(pipex);
		close(pipex->fd[1]);
		exit(1);
	}
	close(pipex->fd[1]);
	execve(cmd, pipex->args, env);
	return (1);
}

int	handle_parent(t_pipex *pipex, char **env)
{
	char	*cmd;

	waitpid(pipex->pid, NULL, 0);
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[1]);
	dup2(pipex->outfile, STDOUT_FILENO);
	parse_env(pipex, env, 2);
	cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!cmd)
	{
		error(pipex->cmd2);
		clean_pipex(pipex);
		exit(1);
	}
	close(pipex->fd[0]);
	execve(cmd, pipex->args, env);
	return (1);
}
