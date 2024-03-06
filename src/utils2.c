/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:34:59 by davda-si          #+#    #+#             */
/*   Updated: 2024/03/06 20:03:59 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	odd_fork(t_table *ph, int num)
{
	if (num == ph->philo - 1)
	{
		pthread_mutex_lock(&(ph->forks[0]));
		pthread_mutex_lock(&(ph->forks[num]));
		if (check_life(ph))
		{
			pthread_mutex_unlock(&(ph->forks[num]));
			pthread_mutex_unlock(&(ph->forks[0]));
			return (1);
		}
	}
	else
	{
		pthread_mutex_lock(&(ph->forks[num]));
		pthread_mutex_lock(&(ph->forks[num + 1]));
		if (check_life(ph))
		{
			pthread_mutex_unlock(&(ph->forks[num + 1]));
			pthread_mutex_unlock(&(ph->forks[num]));
			return (1);
		}
	}
	return (0);
}

int	even_fork(t_table *ph, int num)
{
	if (num == ph->philo - 1)
	{
		pthread_mutex_lock(&(ph->forks[0]));
		pthread_mutex_lock(&(ph->forks[num]));
		if (check_life(ph))
		{
			pthread_mutex_unlock(&(ph->forks[0]));
			pthread_mutex_unlock(&(ph->forks[num]));
			return (1);
		}
	}
	else
	{
		pthread_mutex_lock(&(ph->forks[num]));
		pthread_mutex_lock(&(ph->forks[num + 1]));
		if (check_life(ph))
		{
			pthread_mutex_unlock(&(ph->forks[num]));
			pthread_mutex_unlock(&(ph->forks[num + 1]));
			return (1);
		}
	}
	return (0);
}
