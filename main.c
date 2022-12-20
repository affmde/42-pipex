/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:20:35 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/20 09:59:55 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid1;
	int	infile;
	int outfile;
	
	if (argc != 5)
		return (0);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY);
	pipex(infile, outfile);
	
	/*
	pid1 = fork();
	if (pid1 < 0)
	{
		error("Failed to fork.");
		return (0);
	}
	if (pid1 > 0)
	{
		waitpid(pid1, NULL, 0);
		ft_printf("parent: %d\n", pid1);
	}
	if (pid1 == 0)
		ft_printf("child: %d\n", pid1);
	ft_printf("HI\n");*/
	return (0);
}
