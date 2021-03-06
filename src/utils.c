/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:01:06 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/12 02:45:46 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*find_image(char *str)
{
	if (open(str, O_RDONLY) < 0)
		ft_error("Error: Image not found");
	return (str);
}

void	ft_init_map(t_struct *map)
{
	map->len = 0;
	map->width = 0;
	map->exit = 0;
	map->collect = 0;
	map->position = 0;
	map->img_height = 61;
	map->img_width = 61;
	map->steps = 0;
	map->time = 0;
	map->frame = 0;
	map->flag = 0;
	map->img_player = find_image("./assets/img/player_right_1.xpm");
	map->img_player2 = find_image("./assets/img/player_right_2.xpm");
	map->img_player3 = find_image("./assets/img/player_left_1.xpm");
	map->img_player4 = find_image("./assets/img/player_left_2.xpm");
	map->img_wall = find_image("./assets/img/wall.xpm");
	map->img_grass = find_image("./assets/img/coin-1.xpm");
	map->img_earth = find_image("./assets/img/cover.xpm");
}

void	ft_init_map2(t_struct *map)
{
	map->img_collect = find_image("./assets/img/coin-1.xpm");
	map->img_collect2 = find_image("./assets/img/coin-2.xpm");
	map->img_collect3 = find_image("./assets/img/coin-3.xpm");
	map->img_collect4 = find_image("./assets/img/coin-4.xpm");
	map->img_exit = find_image("./assets/img/portal.xpm");
	map->img_exit2 = find_image("./assets/img/portal_active.xpm");
	map->img_enemy = find_image("./assets/img/enemy_right_1.xpm");
	map->img_enemy_2 = find_image("./assets/img/enemy_right_2.xpm");
}

int	ft_close_x(t_struct *map)
{
	mlx_destroy_window(map->mlx, map->new_window);
	ft_putendl_fd("You closed window", 1);
	exit(EXIT_SUCCESS);
}

void	which_image(t_struct *map, int w, int l)
{
	if (map->str[w][l] == 'D' && map->frame > 24)
		put_all_imgs('D', map, w, l);
	else if (map->str[w][l] == 'D' && map->frame <= 24)
		put_all_imgs('X', map, w, l);
	if (map->str[w][l] == 'C' && map->frame > 36)
		put_all_imgs('C', map, w, l);
	else if (map->str[w][l] == 'C' && map->frame > 24)
		put_all_imgs('Q', map, w, l);
	else if (map->str[w][l] == 'C' && map->frame <= 24 \
			&& map->frame > 12)
		put_all_imgs('W', map, w, l);
	else if (map->str[w][l] == 'C' && map->frame <= 12)
		put_all_imgs('R', map, w, l);
	if (map->str[w][l] == 'P' && map->frame > 24)
		put_all_imgs('Z', map, w, l);
	else if (map->str[w][l] == 'P' && map->frame <= 24)
		put_all_imgs('V', map, w, l);
	if (map->str[w][l] == 'P' && map->frame > 24 && map->flag == 1)
		put_all_imgs('B', map, w, l);
	else if (map->str[w][l] == 'P' && map->frame <= 24 \
			&& map->flag == 1)
		put_all_imgs('N', map, w, l);
}
