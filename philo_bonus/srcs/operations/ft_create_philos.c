/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:29:21 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/07 18:47:42 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	ft_create_philos(t_data *data)
{
	pid_t	*pid;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philos);
	pid = (pid_t *)malloc(sizeof(int) * data->nbr_philos);
	ft_init_semaphore(data);
	ft_launching_philos(philo, data, pid);
	sem_wait(data->exit);
	ft_kill(data, pid);
	free(philo);
	free(data);
	free(pid);
}

void	ft_launching_philos(t_philo *philo, t_data *data, pid_t *pid)
{
	int			i;

	i = 0;
	data->time_reference = ft_get_time_of_day();
	while (i < data->nbr_philos)
	{
		pid[i] = fork();
		philo[i].last_eat = ft_get_time_of_day();
		philo[i].data = data;
		ft_protected_pids(pid, data, philo, i);
		if (pid[i] == 0)
		{
			philo[i].philo_id = i + 1;
			philo[i].pid = pid[i];
			start_philo(&philo[i]);
		}
		i++;
	}
	eat_statement(philo);
}

void	ft_protected_pids(pid_t	*pid, t_data *data, t_philo *philo, int i)
{
	if (pid[i] == -1)
	{
		while (--i >= 0)
			kill(data->pid_philo[i], SIGKILL);
		free(philo);
		free(data);
		free(pid);
		exit (TRUE);
	}
}

void	eat_statement(t_philo *philo)
{
	pthread_t	thread;

	if (philo->data->nbr_of_meals != 0)
	{
		if (pthread_create(&thread, NULL, ft_eat_checker, philo) != 0)
		{
			printf("Unable to create a thread!!");
			exit(TRUE);
		}
		pthread_detach(thread);
	}
}

void	*start_philo(void *arg)
{
	t_philo		*philo;
	pthread_t	thread;

	philo = (t_philo *)arg;
	if (pthread_create(&thread, NULL, &ft_death_checker, philo) != 0)
	{
		printf("Unable to create a thread\n");
		exit(TRUE);
	}
	pthread_detach(thread);
	philo->meals_counter = 0 ;
	while (1)
		ft_routine(philo);
	return (NULL);
}
