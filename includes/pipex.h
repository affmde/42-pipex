/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:43:46 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/21 12:15:12 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		pid;
	char	*cmd1;
	char	*cmd2;
	char	*path;
	char	**possible_paths;
	char	**args;
}		t_pipex;

void	error(char *cmd);
void	error_exit(char *msg);
int		ft_pipex(t_pipex *pipex, char **env);
int		handle_child(t_pipex *pipex, char **env);
int		handle_parent(t_pipex *pipex, char **env);
void	parse_env(t_pipex *pipex, char **env, int cmd);
void	free_double_arr(char **arr);
void	clean_pipex(t_pipex *pipex);

#endif
