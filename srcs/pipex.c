/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:00:05 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/20 10:13:40 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	pipex(int infile, int outfile)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
	{
		error("Something happened with pipe.");
		return (0);
	}
	pid = fork();
	if (pid < 0)
	{
		error("Fork failed.");
		return (0);
	}
	else if (!pid)
		handle_child();
	else if(pid > 0)
		handle_parent();
}