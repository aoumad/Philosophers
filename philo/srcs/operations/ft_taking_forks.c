/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taking_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:45:24 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/04 19:05:01 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_taking_forks(t_philo *philo)
{
	int	status;

	status = 0;
	if (philo->nbr_philos == 1)
		status = 1;
	pthread_mutex_lock(philo->l_hand);
	ft_affichage("has taken a fork", philo, TRUE);
	pthread_mutex_lock(philo->r_hand);
	if (status != 1)
		ft_affichage("has taken a fork", philo, TRUE);
}
