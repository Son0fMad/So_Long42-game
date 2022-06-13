/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:59 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/12 02:33:04 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_exit(t_struct *map)
{
	int	w;
	int	h;

	w = 0;
	while (map->str[w])
	{
		h = 0;
		while (map->str[w][h])
		{
			if (map->str[w][h] == 'E')
				put_all_imgs('E', map, w, h);
			h++;
		}
		w++;
	}
}

void	game(t_struct *map)
{
	map->mlx = mlx_init();
	map->new_window = mlx_new_window(map->mlx, map->len * 61, \
	map->width * 61, "so_long");
	map_full(map);
	mlx_hook(map->new_window, 2, 0, key_h, map);
	mlx_hook(map->new_window, 17, 1L << 2, ft_close_x, map);
	mlx_loop_hook(map->mlx, ft_patrol_animation, map);
	mlx_loop(map->mlx);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	check_args(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong numbers of arguments\n");
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
			ft_error("Wrong map extension\n");
	}
	else
		ft_error("Wrong argument\n");
}

int	main(int argc, char **argv)
{
	t_struct	map;

	ft_init_map(&map);
	ft_init_map2(&map);
	check_args(argc, argv);
	map_parser(argv[1], &map);
	map_validate(&map);
	game(&map);
	return (0);
}
