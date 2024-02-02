/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:17:33 by david             #+#    #+#             */
/*   Updated: 2024/02/02 16:35:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	check_life(t_table *ph)
{
	pthread_mutex_lock(&(ph->marx->shleep));
	if (ph->dead)
		return (1);
	pthread_mutex_unlock(&(ph->marx->shleep));
	return (0);
}

static int	lock_forks(t_table *ph, int num, int flag)
{
	if (flag == 0)
	{
		pthread_mutex_lock(&(ph->forks[num + 1]));
		if (check_life(ph))
		{
			pthread_mutex_unlock(&(ph->forks[num + 1]));
			return (0);
		}
		print_st(ph->marx, ph->marx->dex, "has taken a fork");
		pthread_mutex_lock(&(ph->forks[num]));
		if (check_life(ph))
		{
			pthread_mutex_unlock(&(ph->forks[num]));
			return (0);
		}
		print_st(ph->marx, ph->marx->dex, "has taken a fork");
	}
	else
	{
		pthread_mutex_unlock(&(ph->forks[num + 1]));
		pthread_mutex_unlock(&(ph->forks[num]));
	}
	return (1);
}

static void	eat(t_table *ph)
{
	if (lock_forks(ph, ph->marx->dex, 0))
	{
		pthread_mutex_lock(&(ph->marx->eatin));
		ph->marx->ate++;
		print_st(ph->marx, ph->marx->dex, "eating");
		ph->marx->time_meal = timer() + ph->tm_die;
		pthread_mutex_unlock(&(ph->marx->eatin));
		lock_forks(ph, ph->marx->dex, 1);
	}
	else
	{
		
	}
	return ;
}


void	*ft_life(void *arg)
{
	t_philo		*marx;
	t_table		*ph;

	marx = (t_philo *)arg;
	ph = marx->plate;
	pthread_mutex_lock(&marx->shleep);
	marx->time_meal = timer() + ph->tm_die;
	pthread_mutex_unlock(&marx->shleep);
	while (1)
	{
		if (check_life(ph))
			return (NULL);
		eat(ph);
		if (check_life(ph))
			return (NULL);
		print_st(marx, marx->dex, "sleeping");
		usleep(ph->tm_sleep);
		if (check_life(ph))
			return (NULL);
		print_st(marx, marx->dex, "thinking");
		if (check_life(ph))
			return (NULL);
	}
}
