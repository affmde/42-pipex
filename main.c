/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:20:35 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/20 11:47:27 by andrferr         ###   ########.fr       */
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
	{
		error("Failed to open infile.");
		return (0);
	}
	pipex.outfile = open(argv[argc - 1], O_WRONLY);
	if (pipex.outfile < 0)
	{
		close(pipex.infile);
		error("Failed to open the outfile.");
		return (0);
	}
	ft_pipex(&pipex, env);
	return (0);
}
