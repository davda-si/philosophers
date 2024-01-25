/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:25:11 by david             #+#    #+#             */
/*   Updated: 2024/01/25 17:32:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
			if (philo_ate())
			{
				printf("Philo died\n");
				return (1);
			}
		i++;
		}
	}
}
