/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:32:52 by david             #+#    #+#             */
/*   Updated: 2024/03/06 16:23:19 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_st(t_philo *marx, int philo_nb, char *flag)
{
	pthread_mutex_lock(&(marx->writing));
	printf("%d %d %s\n", (timer() - marx->plate->time), philo_nb + 1, flag);
	pthread_mutex_unlock(&(marx->writing));
}

static int	philo_ate(t_table *ph, t_philo *marx)
{
	int	i;

	if (ph->philo == 1)
	{
		ft_usleep(ph->tm_die, ph);
		return (1);
	}
	pthread_mutex_lock(&(ph->locker));
	if ((ph->meals > 0) && (marx->ate >= ph->meals))
		ph->full++;
	pthread_mutex_unlock(&(ph->locker));
	pthread_mutex_lock(&(ph->locker));
	if ((timer() - marx->time_meal) >= ph->tm_die)
		ph->dead = 1;
	i = ph->dead;
	pthread_mutex_unlock(&(ph->locker));
	return (i);
}

void	ft_usleep(int time, t_table *ph)
{
	long int	st;

	st = timer();
	while (timer() < time + st)
	{
		pthread_mutex_lock(&(ph->locker));
		if (ph->dead)
		{
			pthread_mutex_unlock(&(ph->locker));
			break ;
		}
		pthread_mutex_unlock(&(ph->locker));
		usleep(100);
	}
}

static int	check_full(t_table *ph)
{
	if (ph->full >= ph->philo)
	{
		pthread_mutex_lock(&(ph->locker));
		ph->dead = 1;
		pthread_mutex_unlock(&(ph->locker));
		return (1);
	}
	return (0);
}

void	*grim(void *arg)
{
	t_philo		*marx;
	t_table		*ph;
	int			i;

	marx = (t_philo *)arg;
	ph = marx->plate;
	while (1)
	{
		i = 0;
		pthread_mutex_lock(&(ph->locker));
		ph->full = 0;
		pthread_mutex_unlock(&(ph->locker));
		while (i < ph->philo)
		{
			if (philo_ate(ph, &(marx[i])))
			{
				print_st(marx, i, "is dead");
				return (NULL);
			}
			i++;
		}
		if (check_full(ph))
			return (NULL);
	}
}
