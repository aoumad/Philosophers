/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:32:09 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/04 19:32:20 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_death_checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->died != DEAD)
	{
		if (ft_get_time_of_day() - philo->last_eat >= (long)philo->time_to_die)
		{
			pthread_mutex_lock(&philo->lock_dead);
			philo->data->died = DEAD;
			philo->dead_time = ft_get_time_of_day() - philo->time_reference;
			ft_affichage("is died", philo, DEAD);
		}
	}
	return (NULL);
}
