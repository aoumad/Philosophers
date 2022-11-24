/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:51:26 by aoumad            #+#    #+#             */
/*   Updated: 2022/07/16 17:25:17 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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
