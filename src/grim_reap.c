/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:25:11 by david             #+#    #+#             */
/*   Updated: 2024/01/29 18:51:55 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	philo_ate(t_table *ph, t_philo *marx)
{
	pthread_mutex_lock(&(marx->eatin));
	if (marx->ate >= ph->meals)
		marx->last_meal = 1;
	if (timer() >= ph->tm_die)
		ph->dead = 1;
	pthread_mutex_unlock(&(marx->eatin));
	return (ph->dead);
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
		while (i < ph->philo)
		{
			if (philo_ate(ph, &(ph->marx[i])))
			{
				print_st(marx, i, "dead");
				return (1);
			}
		i++;
		}
	}
}
