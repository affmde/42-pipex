/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:20:35 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/27 21:36:13 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static void	call_error(t_pipex *pipex, char *argv, int error_code)
{
	clean_pipex(pipex);
	error(argv, error_code);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	if (argc != 5)
		return (error_msg("Not right number of arguments"));
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (1);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		call_error(pipex, argv[1], 0);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 00644);
	if (pipex->outfile < 0)
		call_error(pipex, argv[4], 1);
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	if (!parse_env(pipex, env))
		return (1);
	if (!ft_pipex(pipex, env))
		return (1);
	return (EXIT_SUCCESS);
}