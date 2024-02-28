/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:32:52 by david             #+#    #+#             */
/*   Updated: 2024/02/28 18:04:58 by david            ###   ########.fr       */
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
	pthread_mutex_lock(&(marx->eatin));
	if (marx->ate >= ph->meals)
		marx->last_meal = 1;
	if ((timer() - marx->time_meal) >= ph->tm_die)
		ph->dead = 1;
	pthread_mutex_unlock(&(marx->eatin));
	return (ph->dead);
}

void	*grim(void *arg)
{
	t_philo		*marx;
	t_table		*ph;
	int			i;
	int			fed;
	
	marx = (t_philo *)arg;
	ph = marx->plate;
	while (1)
	{
		fed = 0;
		i = 0;
		while (i < ph->philo)
		{
			if (philo_ate(ph, &(marx[i])))
			{
				print_st(marx, i, "is dead");
				return (NULL);
			}
			fed += ph->marx[i].last_meal;
			i++;
		}
		pthread_mutex_lock(&(marx->eatin));
		if (fed == ph->philo)
		{
			pthread_mutex_unlock(&(marx->eatin));
			return (NULL);
		}
		pthread_mutex_unlock(&(marx->eatin));
	}
}
