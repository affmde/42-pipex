/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:43:46 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/30 16:03:41 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		pid;
	int		pid2;
	char	*cmd1;
	char	*cmd2;
	char	*path;
	char	**possible_paths;
	char	**args;
	char	*path_cmd;
}		t_pipex;

int		error(char *cmd, int error_code);
int		error_msg(char *msg, int show_mess);
void	choose_error(t_pipex *pipex, int process);
int		ft_pipex(t_pipex *pipex, char **argv, char **env);
int		process_one(t_pipex *pipex, char **argv, char **env);
int		process_two(t_pipex *pipex, char **argv, char **env);
int		parse_env(t_pipex *pipex, char **env);
void	free_double_arr(char **arr);
void	clean_pipex(t_pipex *pipex);

#endif
