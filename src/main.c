/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:37:06 by david             #+#    #+#             */
/*   Updated: 2024/01/22 17:01:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo(t_table *ph)
{
	int	i;

	i = 0;
	ph->end = 0;
	ph->marx = ft_calloc(sizeof(t_table), ph->philo);
	while (i < ph->philo)
	{
		ph->marx[i].dex = i + 1;
		ph->marx[i].ate = 0;
		ph->marx[i].life = 0;
		ph->marx[i].dead = 0;
		i++;
	}
}

static int	ft_start(t_table *ph)
{
	if (ft_mut(ph) && ft_philo(ph) && ft_start_thd(ph))
	{
		if ()
	}
}

static void	ft_start_thd(t_table ph)
{
	int	i;

	i = 0;
	while (i < ph->philo)
	{
		if (pthread_create(&ph->id[i], NULL, &ft_life, &ph->marx[i]));
			return (NULL);
		i++;
		usleep(2 * 1000);
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
	ft_save_args(&ph, av);
	ft_start(ph);
	return (0);
}
