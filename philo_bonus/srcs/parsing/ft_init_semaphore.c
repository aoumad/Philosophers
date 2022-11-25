/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_semaphore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:01:26 by aoumad            #+#    #+#             */
/*   Updated: 2022/11/25 11:24:01 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	ft_init_semaphore(t_data *data)
{
	sem_unlink("/forks");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->nbr_philos);
	sem_unlink("/write_sem");
	data->write_sem = sem_open("/write_sem", O_CREAT, 0644, 1);
	sem_unlink("/exit");
	data->exit = sem_open("/exit", O_CREAT, 0644, 0);
	sem_unlink("/dead_sem");
	data->dead_sem = sem_open("/dead_sem", O_CREAT, 0644, 1);
	sem_unlink("/eat_enough");
	data->eat_enough = sem_open("/eat_enough", O_CREAT, 0644, 0);
}
