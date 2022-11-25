/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:58:03 by aoumad            #+#    #+#             */
/*   Updated: 2022/11/25 16:24:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_affichage(char *message, t_philo *philo, int status)
{
	long	time;

	time = ft_get_time_of_day() - philo->time_reference;
	pthread_mutex_lock(&philo->lock_print);
	if (status == DEAD)
	{
		pthread_mutex_lock(&philo->lock_dead);
		// data->died = DEAD;
		philo->dead_time = ft_get_time_of_day() - \
		philo->time_reference;
		printf("%ld\t%d\t%s\n", philo->dead_time, philo->id + 1, message);
	}
	else if (status == DONE_ROUTINE)
		printf("%s\n", message);
	else if (status == TRUE)
	{
		printf("%ld\t%d\t%s\n", time, philo->id + 1, message);
		pthread_mutex_unlock(&philo->lock_print);
	}
}
