/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:39:35 by aoumad            #+#    #+#             */
/*   Updated: 2022/11/24 18:53:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id & 1)
		usleep(50);
	while (philo->data->died != DEAD && philo->all_ate != DONE_ROUTINE)
	{
		ft_taking_forks(philo);
		ft_eating_case(philo);
		ft_sleeping_thinking(philo);
	}
	return (NULL);
}
