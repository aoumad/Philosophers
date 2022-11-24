/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:07:58 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/07 17:08:04 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_init_args(int argc, char **argv, t_data *data)
{
	data->nbr_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->died = FALSE;
	if (argc == 6)
		data->nbr_of_meals = ft_atoi(argv[5]);
	else
		data->nbr_of_meals = 0;
}
