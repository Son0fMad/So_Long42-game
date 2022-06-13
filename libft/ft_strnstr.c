/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:10:26 by dcloud            #+#    #+#             */
/*   Updated: 2022/02/02 23:23:06 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	m;
	size_t	c;

	m = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[m] && m < len)
	{
		c = 0;
		while ((m + c) < len && needle[c] == haystack[m + c])
		{
			if (needle[c + 1] == '\0')
				return ((char *)haystack + m);
			c++;
		}
		m++;
	}
	return (0);
}
