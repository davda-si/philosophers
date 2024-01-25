/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:37:06 by david             #+#    #+#             */
/*   Updated: 2024/01/25 17:39:49 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_start(t_table *ph)
{
	if (ft_mut(ph))
	{
		free(ph->forks);
		return (1);
	}
	if (ft_pht(ph))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*ph;

	ph = (t_table *)ft_calloc(sizeof(t_table), 1);
	if (!ph)
		return (1);
	if (ac != 5 && ac != 6)
	{
		printf("Error w/ arg num\n");
		free(ph);
		return (1);
	}
	if (pars(av))
	{
		printf("Args incorrect\n");
		free(ph);
		return (1);
	}
	ft_save_args(ph, av);
	if (ft_start(ph))
		return (1);
	free(ph->forks);
	free(ph);
	return (0);
}
