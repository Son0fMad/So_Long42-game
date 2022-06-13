/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:22:30 by dcloud            #+#    #+#             */
/*   Updated: 2022/02/02 23:20:05 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	t;

	t = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize)
	{
		while (src[t] && (t < dstsize - 1))
		{
			dst[t] = src[t];
			t++;
		}
	}
	dst[t] = '\0';
	return (ft_strlen(src));
}
