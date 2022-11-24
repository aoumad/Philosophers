/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:57:58 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/07 11:01:26 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	*ft_death_checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_get_time_of_day() - philo->last_eat >= \
		(long)philo->data->time_to_die)
		{
			sem_wait(philo->data->dead_sem);
			ft_affichage("is died", philo->philo_id, philo->data, DEAD);
			sem_post(philo->data->exit);
		}
	}
	return (NULL);
}

void	*ft_eat_checker(void *ptr)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)ptr;
	while (i < philo->data->nbr_philos)
	{
		sem_wait(philo->data->eat_enough);
		i++;
	}
	ft_affichage("All philosophers ate", philo->philo_id,
		philo->data, DONE_ROUTINE);
	sem_post(philo->data->exit);
	return (NULL);
}
