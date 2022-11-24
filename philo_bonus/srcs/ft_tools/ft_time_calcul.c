/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_calcul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:32:09 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/07 18:48:39 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

long	ft_get_time_of_day(void)
{
	struct timeval	tp;
	long			time_in_ms;

	gettimeofday(&tp, NULL);
	time_in_ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time_in_ms);
}

void	ft_usleep(int ms)
{
	long	time;

	time = ft_get_time_of_day();
	usleep(ms * 900);
	while (ft_get_time_of_day() < time + ms)
		usleep(20);
}
