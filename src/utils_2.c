/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:26:24 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/12 01:47:01 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_patrol_animation(t_struct *map)
{
	int	w;
	int	l;

	w = 0;
	if (((double)(clock)()) / CLOCKS_PER_SEC - map->time >= (double)1 / 10)
	{
		map->frame++;
		map->time = (double)(clock()) / CLOCKS_PER_SEC;
	}
	if (map->frame > 49)
		map->frame = 0;
	while (map->str[w])
	{
		l = 0;
		while (map->str[w][l])
		{
			which_image(map, w, l);
			l++;
		}
		w++;
	}
	return (0);
}

void	make_sound(char *sound, char *message)
{
	int		res;
	char	*sound_path;

	sound_path = ft_strjoin("afplay ./assets/sound/", sound);
	res = fork();
	if (res == 0)
	{
		system(" kill $(ps | grep tea | head -n 1 | awk '{print $1}')");
		system(sound_path);
		exit(0);
	}
	free(sound_path);
	if (message)
		ft_putendl_fd(message, 1);
}
