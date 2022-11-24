/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:02:13 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/06 17:12:59 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	ft_routine(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_affichage("has taken a fork", philo->philo_id, philo->data, TRUE);
	sem_wait(philo->data->forks);
	ft_affichage("has taken a fork", philo->philo_id, philo->data, TRUE);
	philo->meals_counter++;
	if (philo->meals_counter == philo->data->nbr_of_meals)
		sem_post(philo->data->eat_enough);
	philo->time_to_kill = ft_get_time_of_day() + philo->data->time_to_die;
	ft_affichage("is eating", philo->philo_id, philo->data, TRUE);
	philo->last_eat = ft_get_time_of_day();
	ft_usleep(philo->data->time_to_eat);
	ft_affichage("is sleeping", philo->philo_id, philo->data, TRUE);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	ft_usleep(philo->data->time_to_sleep);
	ft_affichage("is thinking", philo->philo_id, philo->data, TRUE);
}
