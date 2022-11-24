/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaspinoza <anaspinoza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:05:11 by aoumad            #+#    #+#             */
/*   Updated: 2022/11/24 15:53:26 by anaspinoza       ###   ########.fr       */
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
