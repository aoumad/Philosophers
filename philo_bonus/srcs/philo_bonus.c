/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:02:02 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/07 10:26:04 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
	return (0);
}
