/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:17:33 by david             #+#    #+#             */
/*   Updated: 2024/01/31 18:51:43 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	lock_forks(t_table *ph, int num, int flag)
{
	if (flag == 0)
	{
		pthread_mutex_lock(&(ph->forks[num + 1]));
		pthread_mutex_lock(&(ph->forks[num]));
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
		ph->marx->time_meal = timer() + ph->tm_die;
		print_st(ph->marx, ph->marx->dex, "has taken a fork");
		pthread_mutex_unlock(&(ph->marx->eatin));
		lock_forks(ph, ph->marx->dex, 1);
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
		if (ph->dead)
			return (NULL);
		eat(ph);
		if (ph->dead)
			return (NULL);
		print_st(marx, marx->dex, "sleeping");
		usleep(ph->tm_sleep);
		if (ph->dead)
			return (NULL);
		print_st(marx, marx->dex, "thinking");
		if (ph->dead)
			return (NULL);
		
	}
}
