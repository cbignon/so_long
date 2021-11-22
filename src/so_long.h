/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:06:18 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/19 16:41:52 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __MACH__
#  include "../lib/mlx/mlx.h"
#  include "../lib/mlx/mlx_int.h"
#  include "../lib/mlx/mlx_new_window.h"
#  include "../lib/mlx/mlx_opengl.h"
#  include "../lib/mlx/mlx_png.h"
# elif __linux__
#  include "../lib/mlx_linux/mlx.h"
#  include "../lib/mlx_linux/mlx_int.h"
#  include "X11/keysym.h"
#  include <unistd.h>
#  include <fcntl.h>
# endif

# include "../lib/libft/libft.h"

typedef struct s_map
{
	int		pl;
	int		coll;
	int		exit;
	int		map_line;
	int		map_row;
	int		width;
	int		height;
	char	**map2d;
	int		error;
	t_img	*empty;
	t_img	*out;
	t_img	*flower;
	t_img	*bush;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		collected;
	int		way;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			on;
	t_map		*map;
	t_player	*player;
	t_img		*img_r;
	t_img		*img_l;
}	t_data;

int		ft_check_file_ext(char *arg);
int		check_map(char **argv, t_data *data);
int		ft_map_error(int code, t_data *data);
void	init_struct(t_data *data);
void	open_game(t_data *data);
void	draw_map(t_data *data);
void	load_img(t_data *data);
void	ft_load_xpm(t_data *data, t_img *img, char *path);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
int		victory(t_data *data);
int		close_game(t_data *data);
int		my_key_hook(int key, t_data *data);
int		no_event(t_data *data);
void	free_struct(t_data *data);
void	free_img(t_data *data);
void	ft_simple_free(t_data *data);
void	ft_free_tab(t_data *data);
int		ft_end(t_data *data);
void	end_mlx(t_data *data);

# define SAND		0xF5DCA0
# define KEY_A		97
# define KEY_D		100
# define KEY_S		115
# define KEY_W		119
# define BOLD		"\e[1m"
# define GREEN_T	"\e[92m"
# define RESET		"\e[0m"

#endif