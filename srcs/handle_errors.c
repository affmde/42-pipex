/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:01:54 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/21 17:48:59 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error(char *cmd)
{
	perror(cmd);
	exit (1);
}

int	error_msg(char *msg)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(msg, 2);
	return (1);
}
