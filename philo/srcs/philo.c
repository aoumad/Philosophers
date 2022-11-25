/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:28:00 by aoumad            #+#    #+#             */
/*   Updated: 2022/11/25 17:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(*data));
	if (ft_valid_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_init_args(argc, argv, data);
	if (ft_check_pointing_cmd(argc, argv, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_create_philos(data);
	ft_mutex_destroy(data);
	free(data->philo);
	free(data->forks);
	free(data);
	return (0);
}
