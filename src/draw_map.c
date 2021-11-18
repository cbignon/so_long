/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:59:42 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/18 18:05:12 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_event(t_data *data)
{
	draw_map(data);
	if (data->on == -1)
		mlx_loop_end(data->mlx_ptr);
	return(0);
}

int	my_key_hook(int key, t_data *data)
{
	int	ret;

	ret = -1;
	if (key == KEY_A) //gauche
		ret = move_left(data);
	else if (key == KEY_D) //droite
		ret = move_right(data);
	else if (key == KEY_S) //bas
		ret = move_down(data);
	else if (key == KEY_W) //haut
		ret = move_up(data);
	else if (key == 53 || key == 65307)
		mlx_loop_end(data->mlx_ptr);
	if (ret == 0)
	{
		data->player->moves++;
		ft_putnbr_fd((data->player->moves), 1);
		if (data->player->moves == 1)
			ft_putstr_fd(" step", 1);
		else
			ft_putstr_fd(" steps", 1);
		ft_putchar_fd('\n', 1);
	}
	// else if (ret == 1)
	// {
	// 	//draw_map(data);
	// 	//close_game(data);
	// 	//exit (0);
	// 	return (-1);
	// }
	return (0);
}

int	close_game(t_data *data)
{
		free_struct(data);
		return (0);
}

void	open_game(t_data *data)
{
	int	screen_x;
	int screen_y;
	
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->width,
		data->map->height, "so_long");
	mlx_get_screen_size(data->mlx_ptr,&screen_x, &screen_y);
	if (data->map->width > screen_x || data->map->height >  screen_y)
	{
		ft_putstr_fd("Map is too big for your screen!\n", 1);
		close_game(data);
	}
	load_img(data);
	return ;
}

void	load_img(t_data *data)
{
	data->img_r->image = mlx_xpm_file_to_image(data->mlx_ptr, "./src/graph/fox-right32x32.xpm",
		&(data->img_r->width), &(data->img_r->height));
	if (data->img_r->image == NULL)
	{
		ft_putstr_fd("echec xpm to im 1\n", 1);
		return ;
	}
	data->img_l->image = mlx_xpm_file_to_image(data->mlx_ptr, "./src/graph/fox-left32x32.xpm",
		&(data->img_l->width), &(data->img_l->height));
	if (data->img_l->image == NULL)
	{
		ft_putstr_fd("echec xpm to im 2\n", 1);
		return ;
	}
	data->map->out->image = mlx_xpm_file_to_image(data->mlx_ptr,
		"./src/graph/EXIT32x32.xpm", &(data->map->out->width), &(data->map->out->height));
	if (data->map->out->image == NULL)
	{
		ft_putstr_fd("echec xpm to im 3\n", 1);
		return ;
	}
	data->map->empty->image = mlx_xpm_file_to_image(data->mlx_ptr, "./src/graph/empty32x32.xpm",
		&(data->map->empty->width), &(data->map->empty->height));
	if (data->map->empty->image == NULL)
	{
		ft_putstr_fd("echec xpm to im 4\n", 1);
		return ;
	}
	data->map->bush->image = mlx_xpm_file_to_image(data->mlx_ptr, "./src/graph/Bush32x32.xpm",
		&(data->map->bush->width), &(data->map->bush->height));
	if (data->map->bush->image == NULL)
	{
		ft_putstr_fd("echec bush.xpm to im 5\n", 1);
		return ;
	}
	data->map->flower->image = mlx_xpm_file_to_image(data->mlx_ptr, "./src/graph/flower32x32.xpm",
		&(data->map->bush->width), &(data->map->bush->height));
	if (data->map->flower->image == NULL)
	{
		ft_putstr_fd("echec xpm to im 6\n", 1);
		return ;
	}
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i * 32 < data->map->height)
	{
		if (data->map->map2d[i][j] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map->bush->image,
			j * 32, i * 32);
		if (data->map->map2d[i][j] == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map->flower->image,
			j * 32, i * 32);
		if (data->map->map2d[i][j] == 'P' && data->player->way == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_r->image,
			j * 32, i * 32);
		if (data->map->map2d[i][j] == 'P' && data->player->way == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_l->image,
			j * 32, i * 32);
		if (data->map->map2d[i][j] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map->empty->image,
			j * 32, i * 32);
		if (data->map->map2d[i][j] == 'E')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->map->out->image,
			j * 32, i * 32);
		j++;
		if (j * 32 == data->map->width)
		{
			i++;
			j = 0;
		}
	}
}
