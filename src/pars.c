/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:33:27 by david             #+#    #+#             */
/*   Updated: 2024/03/06 16:21:37 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned int	timer(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_save_args(t_table *ph, char **av)
{
	ph->dead = 0;
	ph->philo = ft_atol(av[1]);
	ph->tm_die = ft_atol(av[2]);
	ph->tm_eat = ft_atol(av[3]);
	ph->tm_sleep = ft_atol(av[4]);
	if (av[5])
		ph->meals = ft_atol(av[5]);
	else
		ph->meals = -1;
}

int	pars(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_invalid(av[i]))
			return (1);
		if (ft_atol(av[i]) <= 0 || ft_atol(av[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}
