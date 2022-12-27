/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:00:05 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/27 21:12:12 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_pipex(t_pipex *pipex, char **env)
{
	if (pipe(pipex->fd) < 0)
		error("Pipe failed", EXIT_FAILURE);
	pipex->pid = fork();
	if (pipex->pid < 0)
		error("Fork failed", EXIT_FAILURE);
	else if (!pipex->pid)
		if (!process_one(pipex, env))
			return (0);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error("Fork failed", EXIT_FAILURE);
	else if (!pipex->pid2)
		if (!process_two(pipex, env))
			return (0);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pipex->pid, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	close(pipex->infile);
	close(pipex->outfile);
	clean_pipex(pipex);
	return (1);
}
