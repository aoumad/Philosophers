/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:21:34 by aoumad            #+#    #+#             */
/*   Updated: 2022/08/04 19:06:35 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_helper_display(void)
{
	ft_putstr_fd(" ____________________________________________________\n", 2);
	ft_putstr_fd("|            Please enter 4 or 5 arguments           |\n", 2);
	ft_putstr_fd("|____________________________________________________|\n", 2);
	ft_putstr_fd("|             [1][Number of philosophers]            |\n", 2);
	ft_putstr_fd("|             [2][Time to die]                       |\n", 2);
	ft_putstr_fd("|             [3][Time to eat]                       |\n", 2);
	ft_putstr_fd("|             [4][Time to sleep]                     |\n", 2);
	ft_putstr_fd("|             [5][Number of meals]                   |\n", 2);
	ft_putstr_fd("|____________________________________________________|\n", 2);
}
