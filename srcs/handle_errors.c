/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:01:54 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/30 15:39:29 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error(char *cmd, int error_code)
{
	perror(cmd);
	exit (error_code);
}

int	error_msg(char *msg, int show_mess)
{
	if (show_mess)
		ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(msg, 2);
	return (EXIT_FAILURE);
}

void	choose_error(t_pipex *pipex, int process)
{
	if (process == 1)
	{
		if (pipex->cmd1[0] == '/')
			error(pipex->args[0], 1);
		else
			error_msg(pipex->args[0], 1);
	}
	else if (process == 2)
	{
		if (pipex->cmd2[0] == '/')
			error(pipex->args[0], 1);
		else
			error_msg(pipex->args[0], 1);
	}
}
