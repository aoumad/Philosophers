/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping_thinking.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:45:39 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/04 19:03:00 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_sleeping_thinking(t_philo *philo)
{
	ft_affichage("is sleeping", philo, TRUE);
	pthread_mutex_unlock(philo->l_hand);
	pthread_mutex_unlock(philo->r_hand);
	ft_usleep(philo->time_to_sleep);
	ft_affichage("is thinking", philo, TRUE);
}
