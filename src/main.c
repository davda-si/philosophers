/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:37:06 by david             #+#    #+#             */
/*   Updated: 2024/02/28 17:48:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_clean(t_table *ph)
{
	int	i;

	i = 0;
	while (i < ph->philo)
	{
		pthread_mutex_destroy(&(ph->forks[i]));
		pthread_mutex_destroy(&(ph->marx[i].eatin));
		pthread_mutex_destroy(&(ph->marx[i].shleep));
		pthread_mutex_destroy(&(ph->marx[i].writing));
		i++;
	}
	free(ph->marx);
	free(ph->forks);
	free(ph->th);
	free(ph);
}

static int	ft_start(t_table *ph)
{
	if (ft_mut(ph))
	{
		free(ph->forks);
		return (1);
	}
	if (ft_pht(ph))
	{
		ft_clean(ph);
		return (1);
	}
	else
		ft_clean(ph);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*ph;

	ph = (t_table *)ft_calloc(sizeof(t_table), 1);
	if (!ph)
		return (1);
	if (ac != 5 && ac != 6)
	{
		printf("Error w/ arg num\n");
		free(ph);
		return (1);
	}
	if (pars(av))
	{
		printf("Args incorrect\n");
		free(ph);
		return (1);
	}
	ft_save_args(ph, av);
	if (ft_start(ph))
		return (1);
	return (0);
}
