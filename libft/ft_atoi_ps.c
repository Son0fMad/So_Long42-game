/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:49:52 by dcloud            #+#    #+#             */
/*   Updated: 2022/02/23 00:10:51 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	pars_minus(const char *str, int *i, long int *n)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*n *= -1;
		(*i)++;
		if (str[*i] == '-' || str[*i] == '+')
			return (0);
	}
	return (1);
}

int	ft_atoi_ps(const char *str, int *num)
{
	int		i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 7 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (!pars_minus (str, &i, &sign))
		return (1);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		if ((res * sign) > 2147483647)
			return (1);
		if ((res * sign) < -2147483648)
			return (1);
		i++;
	}
	*num = res * sign;
	return (0);
}
