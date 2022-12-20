/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:00:05 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/20 12:35:25 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_pipex(t_pipex *pipex, char **env)
{
	if (pipe(pipex->fd) < 0)
	{
		error("Something happened with pipe.");
		return (0);
	}
	pipex->pid = fork();
	if (pipex->pid < 0)
	{
		error("Fork failed.");
		return (0);
	}
	else if (!pipex->pid)
		handle_child(pipex, env);
	else if (pipex->pid > 0)
		handle_parent(pipex, env);
	return (1);
}
