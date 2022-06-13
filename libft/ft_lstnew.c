/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:40:29 by dcloud            #+#    #+#             */
/*   Updated: 2022/02/21 23:39:41 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int num)
{
	t_list	*new;

	new = NULL;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = 0;
	new->next = NULL;
	return (new);
}
