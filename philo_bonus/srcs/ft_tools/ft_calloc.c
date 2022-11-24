/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 08:12:48 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/24 08:12:57 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*add;
	size_t			len;

	len = count * size;
	add = (unsigned char *)malloc(len);
	if (!add)
		return (NULL);
	ft_bzero(add, len);
	return (add);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cast_var;
	size_t			i;

	i = 0;
	cast_var = (unsigned char *)s;
	while (i < n)
		cast_var[i++] = 0;
}
