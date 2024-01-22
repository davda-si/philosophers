/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:48:58 by david             #+#    #+#             */
/*   Updated: 2024/01/22 17:03:24 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_philo(t_table *ph)
{
	int	i;

	i = 0;
	ph->end = 0;
	if (!(ph->marx = ft_calloc(sizeof(t_table), ph->philo)))
		return (1);
	while (i < ph->philo)
	{
		ph->marx[i].dex = i + 1;
		ph->marx[i].ate = 0;
		ph->marx[i].life = 0;
		ph->marx[i].dead = 0;
		i++;
	}
}
