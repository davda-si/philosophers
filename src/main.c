/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:37:06 by david             #+#    #+#             */
/*   Updated: 2024/01/11 19:37:54 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_test(void *add);

int	main()
{
	pthread_t	thread;
	pthread_t	thread2;
	long		i;
	long		j;

	i = 15;
	j = 20;
	pthread_create(&thread, NULL, ft_test, (void *)&i);
	pthread_create(&thread2, NULL, ft_test, (void *)&j);
	pthread_join(thread, NULL);
	pthread_join(thread2, NULL);
	return (0);
}

void	*ft_test(void *add)
{
	long	*i;

	i = (long *)add;
	printf("Add: %ld\n", *i);
	sleep(3);
	printf("Thread finished\n");
	return (NULL);
}
