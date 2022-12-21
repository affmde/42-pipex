/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:20:35 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/21 11:52:06 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (0);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		error_exit(argv[1]);
	pipex.outfile = open(argv[argc - 1], O_WRONLY);
	if (pipex.outfile < 0)
	{
		close(pipex.infile);
		error_exit(argv[4]);
	}
	pipex.cmd1 = argv[2];
	pipex.cmd2 = argv[3];
	ft_pipex(&pipex, env);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	clean_pipex(&pipex);
	return (0);
}
