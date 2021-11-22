/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:59:15 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/20 18:06:29 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*malloc_init_img(t_data *data, t_img *img)
{
	img = malloc(sizeof(t_img));
	if (img == NULL)
	{
		ft_putstr_fd("a malloc problem occured\n", 1);
		ft_simple_free(data);
		end_mlx(data);
		exit (0);
	}
	img->image = NULL;
	return (img);
}

void	*malloc_check(void *ptr, int size)
{
	ptr = malloc(sizeof(char) * size);
	if (!ptr)
	{
		ft_putstr_fd("a malloc problem occured\n", 1);
		exit (0);
	}
	return (ptr);
}

void	init_struct(t_data *data)
{
	data->on = 0;
	data->player = malloc_check(data->player, sizeof(t_player));
	data->map = malloc_check(data->map, sizeof(t_map));
	data->img_r = malloc_init_img(data, data->img_r);
	data->img_l = malloc_init_img(data, data->img_l);
	data->map->bush = malloc_init_img(data, data->map->bush);
	data->map->flower = malloc_init_img(data, data->map->flower);
	data->map->empty = malloc_init_img(data, data->map->empty);
	data->map->out = malloc_init_img(data, data->map->out);
	data->player->x = -1;
	data->player->y = -1;
	data->player->way = 1;
	data->player->moves = 0;
	data->player->collected = 0;
	data->map->pl = 0;
	data->map->exit = 0;
	data->map->coll = 0;
	data->map->error = 0;
	data->map->map_line = 0;
	data->map->map_row = 0;
}

void	ft_load_xpm(t_data *data, t_img *img, char *path)
{
	img->image = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&(img->width), &(img->height));
	if (!img->image)
	{
		ft_putstr_fd("Failed loading image from ", 1);
		ft_putstr_fd(path, 1);
		ft_putchar_fd('\n', 1);
		free_struct(data);
		end_mlx(data);
		exit(0);
	}
}
