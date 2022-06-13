/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:42:03 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/12 01:51:08 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <time.h>
# include "../libft/libft.h"
# include "../miniLibx/mlx.h"
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_struct
{
	char	**str;
	int		len;
	int		width;
	int		position;
	int		wall;
	int		goal;
	int		collect;
	int		exit;
	int		pos_x;
	int		pos_y;
	void	*img_player;
	void	*img_player2;
	void	*img_player3;
	void	*img_player4;
	void	*img_wall;
	void	*img_grass;
	void	*img_earth;
	void	*img_collect;
	void	*img_collect2;
	void	*img_collect3;
	void	*img_collect4;
	void	*img_exit;
	void	*img_exit2;
	void	*img_enemy;
	void	*img_enemy_2;
	void	*victim;
	int		img_height;
	int		img_width;
	int		time;
	int		steps;
	int		frame;
	void	*mlx;
	void	*new_window;
	int		x;
	int		y;
	void	*img;
	int		flag;
}				t_struct;

/*
so_long
*/
void	ft_exit(t_struct *map);
int		main(int argc, char **argv);
void	game(t_struct *map);
void	check_args(int argc, char **argv);
void	ft_error(char *str);

/*
utils
*/
char	*find_image(char *str);
void	ft_init_map(t_struct *map);
void	ft_init_map2(t_struct *map);
int		ft_close_x(t_struct *map);
void	which_image(t_struct *map, int w, int l);

/*
utils_2
*/
int		ft_patrol_animation(t_struct *map);
void	make_sound(char *sound, char *message);

/*
map_reading
*/
void	put_basic_imgs(char symbol, t_struct *map);
void	player_imgs(char symbol, t_struct *map);
void	animation_imgs(char symbol, t_struct *map);
void	put_all_imgs(char symbol, t_struct *map, int x, int y);
void	map_full(t_struct *map);

/*
map_parcing
*/
void	ft_width_map(char *str, t_struct *map);
void	map_parser(char *str, t_struct *map);
void	structure_of_map(char *str, t_struct *map);
void	first_and_last_str_of_map(t_struct *map);
void	map_validate(t_struct *map);

/*
player_move
*/
void	ft_step_printer(t_struct *map);
int		ft_close(t_struct *map, char mes_code);
void	ft_moving(t_struct *map, int x, int y);
void	ft_lets_moving(t_struct *map, int x, int y);
int		key_h(int key_code, t_struct *map);

#endif
