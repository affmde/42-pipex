/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:00:01 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/21 12:33:03 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	clean_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->args)
			free_double_arr(pipex->args);
		if (pipex->possible_paths)
			free_double_arr(pipex->possible_paths);
		if (pipex->path)
			free(pipex->path);
		//free(pipex);
	}
}
