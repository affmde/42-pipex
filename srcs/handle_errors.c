/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:01:54 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/27 21:06:35 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error(char *cmd, int error_code)
{
	perror(cmd);
	exit (error_code);
}

int	error_msg(char *msg)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(msg, 2);
	return (EXIT_FAILURE);
}
