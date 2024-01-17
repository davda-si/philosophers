/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:31:44 by david             #+#    #+#             */
/*   Updated: 2024/01/17 18:30:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_save_args(t_table *ph, char **av)
{
	ph->time = timer();
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
