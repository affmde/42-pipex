/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:20:35 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/18 14:29:28 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	
	if (argc != 5)
		return (0);
	if (pipe(fd) == -1)
		return (0);
	pid1 = fork();
	if (pid1 < 0)
		return (0);
	if (pid1 == 0)
	{
		dup2(fd[1], 1);
		//do something
	}
	waitpid(pid1, NULL, 0);
	ft_printf("%s - %d\n", argv[1], argc);
	return (0);
}