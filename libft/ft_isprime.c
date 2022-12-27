/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:38 by andrferr          #+#    #+#             */
/*   Updated: 2022/12/22 16:19:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprime(int num)
{
	int	i;
	int	prime;

	prime = 1;
	i = 2;
	while (i < num)
	{
		if (num % i == 0)
		{
			prime = 0;
			break ;
		}
		i++;
	}
	if (prime)
		return (1);
	return (0);
}