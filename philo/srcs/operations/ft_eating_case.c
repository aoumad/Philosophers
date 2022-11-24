/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:05:11 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/06 12:55:44 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_eating_case(t_philo *philo)
{
	if (philo->meals_counter == philo->nbr_of_meals && philo->nbr_of_meals != 0)
		philo->all_ate = DONE_ROUTINE;
	if (philo->nbr_of_meals != 0)
		philo->meals_counter += 1;
	ft_affichage("is eating", philo, TRUE);
	philo->last_eat = ft_get_time_of_day();
	ft_usleep(philo->time_to_eat);
}
