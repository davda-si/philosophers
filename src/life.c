/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:17:33 by david             #+#    #+#             */
/*   Updated: 2024/01/29 18:56:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	eat(t_table *ph)
{
	if (lock_forks(ph))
	{
		pthread_mutex_lock(&(ph->marx->eatin));
		ph->marx->ate++;
		ph->marx->time_meal = timer() + ph->tm_die;
		pthread_mutex_unlock(&(ph->marx->eatin));
		unlock_forks(ph);
	}
	return ;
}

void	*ft_life(void *arg)
{
	t_philo		*marx;
	t_table		*ph;

	marx = (t_philo *)arg;
	ph = marx->plate;
	while (1)
	{
		eat(ph);
	}
}
