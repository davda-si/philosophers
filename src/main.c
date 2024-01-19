/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:37:06 by david             #+#    #+#             */
/*   Updated: 2024/01/18 19:39:29 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_philo(t_table *ph)
{
	int	i;

	i = 0;
	while (i < ph->philo)
	{
		ph->marx[i].dex = i + 1;
		ph->marx[i].ate = 0;
		ph->marx[i].life = 0;
		ph->marx[i].dead = 0;
		i++;
	}
}

static void	ft_start_thd(t_table *ph)
{
	int	i;

	i = 0;
	while (i < ph->philo)
	{
		if (pthread_create(&ph->id[i], NULL, &ft_life, &ph->marx[i]));
			return (NULL);
		i++;
		usleep(1000);
	}
	i = 0;
	while (i < ph->philo)
	{
		if (pthread_join(ph->id[i], NULL))
			return (NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_table	*ph;

	if (ac != 5 && ac != 6)
	{
		printf("Error w/ arg num\n");
		return (1);
	}
	if (pars(av))
	{
		printf("Args incorrect\n");
		return (1);
	}
	ft_save_args(&ph, av);
	printf("%d\n%d\n%d\n%d\n%d\n", ph->philo, ph->tm_die, ph->tm_eat, ph->tm_sleep, ph->meals);
	ft_philo(&ph);
	ft_start_thd(&ph);
	return (0);
}
