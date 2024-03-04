/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:32:17 by david             #+#    #+#             */
/*   Updated: 2024/03/04 19:54:11 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_life(t_table *ph)
{
	if (ph->philo == 1)
		return (1);
	pthread_mutex_lock(&(ph->locker));
	if (ph->dead)
	{
		pthread_mutex_unlock(&(ph->locker));
		return (1);
	}
	if (ph->full == ph->philo)
	{
		pthread_mutex_unlock(&(ph->locker));
		return (1);
	}
	pthread_mutex_unlock(&(ph->locker));
	return (0);
}

static int	lock_forks(t_table *ph, int num, int flag)
{
	if (flag == 0)
	{
		if (num == ph->philo - 1)
		{
			pthread_mutex_lock(&(ph->forks[0]));
			pthread_mutex_lock(&(ph->forks[num]));
			if (check_life(ph))
			{
				pthread_mutex_unlock(&(ph->forks[0]));
				pthread_mutex_unlock(&(ph->forks[num]));
				return (0);
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
				return (0);
			}
		}
		print_st(ph->marx, num, "has taken a fork");
		/* pthread_mutex_lock(&(ph->forks[num]));
		if (check_life(ph))
		{
			pthread_mutex_unlock(&(ph->forks[num]));
			if (num == ph->philo - 1)
			{
				pthread_mutex_unlock(&(ph->forks[0]));
				return (0);
			}
			else
			{
				pthread_mutex_unlock(&(ph->forks[num + 1]));
				return (0);
			}
		} */
		print_st(ph->marx, num, "has taken a fork");
	}
	else
	{
		if (num == ph->philo - 1)
			pthread_mutex_unlock(&(ph->forks[0]));
		else
			pthread_mutex_unlock(&(ph->forks[num + 1]));
		pthread_mutex_unlock(&(ph->forks[num]));
	}
	return (1);
}

static int	eat(t_table *ph, t_philo *marx)
{
	if (lock_forks(ph, marx->dex, 0))
	{
		pthread_mutex_lock(&(ph->locker));
		marx->time_meal = timer();
		print_st(ph->marx, marx->dex, "is eating");
		pthread_mutex_unlock(&(ph->locker));
		usleep(ph->tm_eat * 1000);
		pthread_mutex_lock(&(ph->locker));
		marx->ate++;
		pthread_mutex_unlock(&(ph->locker));
		lock_forks(ph, marx->dex, 1);
	}
	else
		return (1);
	return (0);
}


void	*ft_life(void *arg)
{
	t_philo		*marx;
	t_table		*ph;

	marx = (t_philo *)arg;
	ph = marx->plate;
	//marx->time_meal = timer();
	if (marx->dex % 2 == 1)
		ft_usleep(1000, ph);
	while (1)
	{
		if (check_life(ph))
			return (NULL);
		if (eat(ph, marx))
			return (NULL);
		if (check_life(ph))
			return (NULL);
		print_st(marx, marx->dex, "is sleeping");
		ft_usleep(ph->tm_sleep * 1000, ph);
		if (check_life(ph))
			return (NULL);
		print_st(marx, marx->dex, "is thinking");
		if (check_life(ph))
			return (NULL);
	}
}
