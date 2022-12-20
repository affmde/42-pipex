/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:21:51 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/20 11:45:49 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	handle_child(t_pipex *pipex, char **env)
{
	ft_printf("%d\n", pipex->infile);
	return (1);
}

int	handle_parent(t_pipex *pipex, char **env)
{
	ft_printf("%d\n", pipex->outfile);
	return (1);
}
