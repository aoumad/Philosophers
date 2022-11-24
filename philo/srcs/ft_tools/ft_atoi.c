/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <abderazzakoumad@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:32:09 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/04 19:32:20 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(const char *str)
{
	unsigned long	number;
	int				sign;

	sign = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*(str++) - 48);
		if (sign == 1)
		{
			if (number > L_MAX)
				return (-1);
		}
		else
		{
			if (number > (unsigned long )L_MAX + 1)
				return (0);
		}
	}
	return ((int )number * sign);
}
