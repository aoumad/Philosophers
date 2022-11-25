/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:19:32 by aoumad            #+#    #+#             */
/*   Updated: 2022/11/25 18:37:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>

# define ERROR 0
# define VALID 1
# define L_MAX 9223372036854775807

enum e_philo_state
{
	FALSE,
	TRUE,
	DONE_ROUTINE,
	DEAD,
};

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	int				died;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				all_ate;
	pthread_mutex_t	*l_hand;
	pthread_mutex_t	*r_hand;
	int				eating_routine;
	long			dead_time;
	int				meals_counter;
	long			last_eat;
	long			time_reference;
	pthread_t		thread;
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_dead;
	pthread_t		death_thread;
	t_data			*data;
}	t_philo;
void	ft_helper_display(void);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_is_digit(char *str);
long	ft_get_time_of_day(void);
void	ft_affichage(char *message, t_philo *philo, int status);
void	ft_usleep(int ms);
void	ft_init_args(int argc, char **argv, t_data *data);
int		ft_valid_args(int argc, char **argv);
void	ft_mutex_destroy(t_data *data);
void	ft_create_philos(t_data *data);
int		ft_mutex_init(t_data *data);
int		ft_check_pointing_cmd(int argc, char **argv, t_data *data);
void	ft_init_data(t_philo *philo, int nbr_philos, t_data *data);
int		ft_all_ate(t_philo *philo);
void	*ft_routine(void *arg);
void	ft_taking_forks(t_philo *philo);
void	ft_eating_case(t_philo *philo);
void	ft_sleeping_thinking(t_philo *philo);
void	ft_check_all_ate(t_data *data);
void	ft_init_philos(t_philo *philo, t_data *data);

#endif
