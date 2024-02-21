/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:33:57 by david             #+#    #+#             */
/*   Updated: 2024/02/21 19:33:59 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_atol(const char *s)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		res = res * 10 + (s[i++] - '0');
	return (res * sign);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_invalid(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*i;
	size_t	s;

	if (nmemb == 0 || size == 0)
	{
		nmemb++;
		size++;
	}
	s = nmemb * size;
	i = malloc(s);
	if (!i)
		return (NULL);
	memset(i, 0, s);
	return (i);
}

void	print_st(t_philo *marx, int philo_nb, char *flag)
{
	pthread_mutex_lock(&(marx->writing));
	printf("%d %d %s\n", (timer() - marx->plate->time), philo_nb + 1, flag);
	pthread_mutex_unlock(&(marx->writing));
}
