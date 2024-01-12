/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:37:06 by david             #+#    #+#             */
/*   Updated: 2024/01/12 19:40:56 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
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
	
	return (0);
}
