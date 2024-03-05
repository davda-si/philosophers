/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:34:17 by david             #+#    #+#             */
/*   Updated: 2024/03/05 16:55:55 by davda-si         ###   ########.fr       */
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
	int				ate;
	unsigned int	time_meal;
	pthread_mutex_t	eatin;
	pthread_mutex_t	writing;
	t_table			*plate;
}				t_philo;

typedef struct	s_table
{
	pthread_t		*th;
	pthread_t		gr;
	int				dead;
	int				philo;
	int				full;
	unsigned int	tm_die;
	unsigned int	tm_eat;
	int				tm_sleep;
	int				meals;
	unsigned int	time;
	pthread_mutex_t	locker;
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
int				ft_pht(t_table *ph);
void			*ft_life(void *arg);
void			*grim(void *arg);
void			print_st(t_philo *marx, int philo_nb, char *flag);
void			ft_usleep(int time, t_table *ph);

#endif