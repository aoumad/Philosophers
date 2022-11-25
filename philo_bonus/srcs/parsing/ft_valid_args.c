/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:36:40 by aoumad            #+#    #+#             */
/*   Updated: 2022/11/25 12:57:03 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	ft_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		ft_helper_display();
		return (EXIT_FAILURE);
	}
	while (argv[i])
	{
		if (!ft_is_digit(argv[i]) || !ft_atoi(argv[i]))
		{
			printf("ERROR: the argument number %d is invalid!!\n", i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_pointing_cmd(int argc, char **argv, t_data *data)
{
	int	status;

	status = 0;
	if (data->nbr_philos <= 0)
		status = 1;
	if (data->time_to_die < 60)
		status = 2;
	if (data->time_to_eat < 60)
		status = 3;
	if (data->time_to_sleep < 60)
		status = 4;
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		status = 5;
	if (status != 0)
	{
		printf("ERROR: the argument \"%d\" is invalid\n", ft_atoi(argv[status]));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
