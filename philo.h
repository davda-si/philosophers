/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:47:20 by david             #+#    #+#             */
/*   Updated: 2024/01/25 17:28:06 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

typedef struct s_philo
{
	int				dex;
	int				last_meal;
	int				ate;
	int				starve;
	int				check_l;
	int				check_r;
	int				dead;
	pthread_mutex_t	eatin;
	pthread_mutex_t	shleep;
	pthread_mutex_t	writing;
	t_table			*plate;
}				t_philo;

typedef struct	s_table
{
	pthread_t		*th;
	pthread_t		gr;
	int				philo;
	int				tm_die;
	int				tm_eat;
	int				tm_sleep;
	int				meals;
	unsigned int	time;
	pthread_mutex_t	*forks;
	t_philo			*marx;
}			t_table;

int				main(int ac, char **av);
long			ft_atol(const char *s);
int				ft_invalid(char *str);
int				pars(char **av);
void			ft_save_args(t_table *ph, char **av);
unsigned int	timer(void);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_mut(t_table *ph);
void			*ft_life(void *arg);
void			*grim(void *arg);

#endif