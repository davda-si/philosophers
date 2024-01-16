/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:37:06 by david             #+#    #+#             */
/*   Updated: 2024/01/16 20:01:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_table	ph;

	if (ac != 5 && ac != 6)
	{
		printf("Error w/ arg num\n");
		return (1);
	}
	if (pars(av))
	{
		printf("Args incorrect\n");
		return (1);
	}
	ft_save_args(&ph, av);
	printf("%d\n%d\n%d\n%d\n%d\n", ph.philo, ph.tm_die, ph.tm_eat, ph.tm_sleep, ph.meals);
	ph.time = timer();
	if (ph.philo == 1)
	{
		usleep(ph.tm_die);
		printf("dead\n");
	}
	return (0);
}
