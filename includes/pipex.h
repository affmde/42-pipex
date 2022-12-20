/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:43:46 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/20 11:46:03 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int	fd[2];
	int	infile;
	int	outfile;
	int	pid;

}		t_pipex;

void	error(char *str);
int		ft_pipex(t_pipex *pipex, char **env);
int		handle_child(t_pipex *pipex, char **env);
int		handle_parent(t_pipex *pipex, char **env);

#endif
