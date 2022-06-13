/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:22:04 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/12 01:35:13 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_basic_imgs(char symbol, t_struct *map)
{
	if (symbol == '1')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_wall, \
			&map->img_height, &map->img_width);
	if (symbol == '0')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_earth, \
			&map->img_height, &map->img_width);
	if (symbol == 'C')
	{
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_collect, \
			&map->img_height, &map->img_width);
	}
	if (symbol == 'E')
	{
		if (map->collect != 0)
			map->img = mlx_xpm_file_to_image(map->mlx, map->img_exit, \
				&map->img_height, &map->img_width);
		else
		{
			map->img = mlx_xpm_file_to_image(map->mlx, map->img_exit2, \
				&map->img_height, &map->img_width);
		}
	}
}

void	player_imgs(char symbol, t_struct *map)
{
	if (symbol == 'Z')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_player, \
		&map->img_height, &map->img_width);
	if (symbol == 'V')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_player2, \
		&map->img_height, &map->img_width);
	if (symbol == 'B')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_player3, \
		&map->img_height, &map->img_width);
	if (symbol == 'N')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_player4, \
		&map->img_height, &map->img_width);
}

void	animation_imgs(char symbol, t_struct *map)
{
	if (symbol == 'P')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_player, \
		&map->img_height, &map->img_width);
	if (symbol == 'X')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_enemy, \
			&map->img_height, &map->img_width);
	if (symbol == 'D')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_enemy_2, \
			&map->img_height, &map->img_width);
	if (symbol == 'C')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_collect2, \
		&map->img_height, &map->img_width);
	if (symbol == 'Q')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_collect, \
		&map->img_height, &map->img_width);
	if (symbol == 'W')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_collect3, \
		&map->img_height, &map->img_width);
	if (symbol == 'R')
		map->img = mlx_xpm_file_to_image(map->mlx, map->img_collect4, \
		&map->img_height, &map->img_width);
	player_imgs(symbol, map);
}

void	put_all_imgs(char symbol, t_struct *map, int y, int x)
{
	if (symbol == '1' || symbol == '0' || symbol == 'E')
		put_basic_imgs(symbol, map);
	if (symbol == 'P' || symbol == 'X' || symbol == 'D' \
		|| symbol == 'C' || symbol == 'Q' || symbol == 'W' \
		|| symbol == 'R' || symbol == 'Z' || symbol == 'V' \
		|| symbol == 'B' || symbol == 'N')
	{
		if (symbol == 'P')
		{
			map->pos_x = x;
			map->pos_y = y;
		}
		animation_imgs(symbol, map);
	}
	mlx_put_image_to_window(map->mlx, map->new_window, map->img, \
		x * map->img_height, y * map->img_width);
}

void	map_full(t_struct *map)
{
	int	w;
	int	h;

	w = 0;
	while (map->str[w])
	{
		h = 0;
		while (map->str[w][h])
		{
			put_all_imgs(map->str[w][h], map, w, h);
			h++;
		}
		w++;
	}
}
