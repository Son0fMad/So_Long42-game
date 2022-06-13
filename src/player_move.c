/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:54:30 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/12 02:00:10 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_step_printer(t_struct *map)
{
	char	*str;

	str = ft_itoa(map->steps);
	put_all_imgs('1', map, 0, 1);
	put_all_imgs('1', map, 0, 0);
	mlx_string_put(map->mlx, map->new_window, 20, 10, 0xf2f3f4, "Steps: ");
	mlx_string_put(map->mlx, map->new_window, 100, 10, 0xf2f3f4, str);
	ft_putstr_fd("Steps: ", 1);
	ft_putendl_fd(str, 1);
	free(str);
}

int	ft_close(t_struct *map, char mes_code)
{
	mlx_destroy_window(map->mlx, map->new_window);
	if (mes_code == 'C')
		ft_putendl_fd("You closed the window", 1);
	else if (mes_code == 'W')
		make_sound("you_win.mp3", "YOU_WIN! ^_^");
	else if (mes_code == 'D')
		make_sound("game_over.mp3", "GAME_OVER X)");
	exit(EXIT_SUCCESS);
}

void	ft_moving(t_struct *map, int x, int y)
{
	map->str[map->pos_y][map->pos_x] = '0';
	put_all_imgs('0', map, map->pos_y, map->pos_x);
	map->str[map->pos_y + y][map->pos_x + x] = 'P';
	put_all_imgs('P', map, map->pos_y + y, map->pos_x + x);
	map->steps++;
	ft_step_printer(map);
}

void	ft_lets_moving(t_struct *map, int x, int y)
{
	if (map->str[map->pos_y + y][map->pos_x + x] == 'D')
		ft_close(map, 'D');
	else if (map->str[map->pos_y + y][map->pos_x + x] == 'E' \
			&& map->collect == 0)
		ft_close(map, 'W');
	else if (map->str[map->pos_y + y][map->pos_x + x] == 'C')
	{
		make_sound("coin.mp3", NULL);
		ft_moving(map, x, y);
		map->collect = map->collect - 1;
		if (map->collect == 0)
			ft_exit(map);
	}
	else if (map->str[map->pos_y + y][map->pos_x + x] == '0')
		ft_moving(map, x, y);
}

int	key_h(int key_code, t_struct *map)
{
	if (key_code == 13)
		ft_lets_moving(map, 0, -1);
	else if (key_code == 1)
		ft_lets_moving(map, 0, 1);
	else if (key_code == 0)
	{
		map->flag = 1;
		ft_lets_moving(map, -1, 0);
	}
	else if (key_code == 2)
	{
		map->flag = 0;
		ft_lets_moving(map, 1, 0);
	}
	else if (key_code == 53)
		ft_close(map, 'C');
	return (0);
}
