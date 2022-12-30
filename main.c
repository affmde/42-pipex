/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:20:35 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/30 16:18:37 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	if (argc != 5)
		return (error_msg("Not right number of arguments", 0));
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (1);
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	if (!parse_env(pipex, env))
		return (1);
	if (!ft_pipex(pipex, argv, env))
		return (1);
	return (EXIT_SUCCESS);
}
