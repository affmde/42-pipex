/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:01:54 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/21 12:22:23 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(char *cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd, 2);
}

void	error_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
