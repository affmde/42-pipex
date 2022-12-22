/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:20:35 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/22 10:28:16 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_msg("Not right number of arguments"));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		error(argv[1]);
	pipex.outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 00644);
	if (pipex.outfile < 0)
		error(argv[4]);
	pipex.cmd1 = argv[2];
	pipex.cmd2 = argv[3];
	parse_env(&pipex, env);
	if (!ft_pipex(&pipex, env))
		return (1);
	close(pipex.infile);
	close(pipex.outfile);
	clean_pipex(&pipex);
	return (0);
}
