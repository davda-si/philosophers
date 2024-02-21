/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:32:17 by david             #+#    #+#             */
/*   Updated: 2024/02/21 19:33:03 by david            ###   ########.fr       */
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
		if (num == ph->philo - 1)
		{
			pthread_mutex_lock(&(ph->forks[0]));
			if (check_life(ph))
			{
				pthread_mutex_unlock(&(ph->forks[0]));
				return (0);
			}
		}
		else 
		{
			pthread_mutex_lock(&(ph->forks[num + 1]));
			if (check_life(ph))
			{
				pthread_mutex_unlock(&(ph->forks[num + 1]));
				return (0);
			}
		}
		print_st(ph->marx, num, "has taken a fork");
		pthread_mutex_lock(&(ph->forks[num]));
		if (check_life(ph))
		{
			pthread_mutex_unlock(&(ph->forks[num]));
			return (0);
		}
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

static void	eat(t_table *ph, t_philo *test)
{
	if (lock_forks(ph, test->dex, 0))
	{
		test->time_meal = timer();
		print_st(ph->marx, test->dex, "is eating");
		usleep(ph->tm_eat * 1000);
		pthread_mutex_lock(&(ph->marx->eatin));
		test->ate++;
		pthread_mutex_unlock(&(ph->marx->eatin));
		lock_forks(ph, test->dex, 1);
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
	marx->time_meal = timer();
	pthread_mutex_unlock(&marx->shleep);
	if (marx->dex % 2 == 1)
		usleep(1000);
	while (1)
	{
		if (check_life(ph))
			return (NULL);
		eat(ph, marx);
		if (check_life(ph))
			return (NULL);
		print_st(marx, marx->dex, "is sleeping");
		usleep(ph->tm_sleep * 1000);
		if (check_life(ph))
			return (NULL);
		print_st(marx, marx->dex, "is thinking");
		if (check_life(ph))
			return (NULL);
	}
}
