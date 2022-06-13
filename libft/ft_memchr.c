/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:42:36 by dcloud            #+#    #+#             */
/*   Updated: 2022/02/02 22:59:07 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)str)[i] != (unsigned char)c)
		i++;
	if (i != n && ((unsigned char *)str)[i] == (unsigned char)c)
		return ((void *)str + i);
	return (NULL);
}
