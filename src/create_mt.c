/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:32:32 by david             #+#    #+#             */
/*   Updated: 2024/03/06 15:59:15 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	lf_fork(t_table *ph)
{
	int	i;

	i = 0;
	while (i < ph->philo)
	{
		if (pthread_mutex_init(&(ph->forks[i]), NULL))
		{
			printf("Error initializing mutexes\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_mut(t_table *ph)
{
	ph->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * ph->philo);
	if (!ph->forks)
		return (1);
	if (lf_fork(ph))
		return (1);
	return (0);
}

static int	ft_philo(t_table *ph)
{
	int	i;

	i = 0;
	ph->marx = ft_calloc(sizeof(t_philo), ph->philo);
	if (!(ph->marx))
		return (1);
	while (i < ph->philo)
	{
		ph->marx[i].plate = ph;
		ph->marx[i].dex = i;
		ph->marx[i].ate = 0;
		if (pthread_mutex_init(&(ph->marx[i].eatin), NULL))
		{
			printf("Error initializing mutexes\n");
			return (1);
		}
		if (pthread_mutex_init(&(ph->marx[i].writing), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(ph->locker), NULL))
		return (1);
	return (0);
}

static int	ft_start_thd(t_table *ph)
{
	int	i;

	i = 0;
	ph->time = timer();
	while (i < ph->philo)
	{
		ph->marx[i].time_meal = timer();
		if (pthread_create(&ph->th[i], NULL, &ft_life, &ph->marx[i]))
			return (1);
		i++;
	}
	if (pthread_create(&ph->gr, NULL, &grim, ph->marx))
		return (1);
	i = 0;
	while (i < ph->philo)
	{
		pthread_join(ph->th[i], NULL);
		i++;
	}
	pthread_join(ph->gr, NULL);
	return (0);
}

int	ft_pht(t_table *ph)
{
	ph->th = (pthread_t *)ft_calloc(sizeof(pthread_t), ph->philo);
	if (!(ph->th))
	{
		free(ph->th);
		return (1);
	}
	if (ft_philo(ph))
	{
		free(ph->marx);
		printf("Error trying to sit down the philosophers\n");
		return (1);
	}
	if (ft_start_thd(ph))
	{
		printf("Thread Error\n");
		return (1);
	}
	return (0);
}
