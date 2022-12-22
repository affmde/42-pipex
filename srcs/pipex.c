/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:00:05 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/22 10:04:06 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_pipex(t_pipex *pipex, char **env)
{
	if (pipe(pipex->fd) < 0)
		error("Pipe failed");
	pipex->pid = fork();
	if (pipex->pid < 0)
		error("Fork failed");
	else if (!pipex->pid)
	{
		if (!handle_child(pipex, env))
			return (0);
	}
	else if (pipex->pid > 0)
		if (!handle_parent(pipex, env))
			return (0);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	clean_pipex(pipex);
	return (1);
}
