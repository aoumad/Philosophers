/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:27:32 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/04 18:51:53 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_mutex_init(t_data *data)
{
	int	count;

	count = data->nbr_philos;
	if (pthread_mutex_init(&data->philo->lock_print, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->philo->lock_dead, NULL))
		return (EXIT_FAILURE);
	data->forks = malloc(sizeof(pthread_mutex_t) * count);
	while (count--)
	{
		if (pthread_mutex_init(&data->forks[count], NULL))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
