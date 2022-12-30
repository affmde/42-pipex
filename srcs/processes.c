/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:21:51 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/30 16:21:17 by andrferr         ###   ########.fr       */
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

static void	handle_no_cmd(t_pipex *pipex, int error_code)
{
	choose_error(pipex, error_code);
	clean_pipex(pipex);
	exit (EXIT_FAILURE);
}

int	process_one(t_pipex *pipex, char **argv, char **env)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		error(argv[1], 0);
	close(pipex->fd[0]);
	if (dup2(pipex->fd[1], STDOUT_FILENO) < 0)
		return (0);
	if (dup2(pipex->infile, STDIN_FILENO) < 0)
		return (0);
	pipex->args = ft_split(pipex->cmd1, ' ');
	if (!pipex->args)
		return (0);
	if (access(pipex->args[0], 0) == 0)
		pipex->path_cmd = pipex->args[0];
	else
		pipex->path_cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!pipex->path_cmd)
		handle_no_cmd(pipex, 1);
	close(pipex->fd[1]);
	close(pipex->infile);
	if (execve(pipex->path_cmd, pipex->args, env) < 0)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	process_two(t_pipex *pipex, char **argv, char **env)
{
	pipex->outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 00644);
	if (!pipex->outfile)
		error(argv[4], 1);
	close(pipex->fd[1]);
	if (dup2(pipex->fd[0], STDIN_FILENO) < 0)
		return (0);
	if (dup2(pipex->outfile, STDOUT_FILENO) < 0)
		return (0);
	pipex->args = ft_split(pipex->cmd2, ' ');
	if (!pipex->args)
		return (0);
	if (access(pipex->args[0], 0) == 0)
		pipex->path_cmd = pipex->args[0];
	else
		pipex->path_cmd = get_command(pipex->possible_paths, pipex->args[0]);
	if (!pipex->path_cmd)
		handle_no_cmd(pipex, 2);
	close(pipex->fd[0]);
	close(pipex->outfile);
	if (execve(pipex->path_cmd, pipex->args, env) < 0)
	{
		clean_pipex(pipex);
		return (0);
	}
	return (EXIT_FAILURE);
}
