/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:09:00 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/02 19:34:59 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	t;

	t = 0;
	while ((s1[t] && s2[t]) && (s1[t] == s2[t]))
		t++;
	return ((unsigned char)s1[t] - (unsigned char)s2[t]);
}
