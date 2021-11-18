/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:59:15 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/18 18:19:14 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_data *data)
{
	data->on = 0;
	data->player = malloc(sizeof(t_player));
	data->img_r = malloc(sizeof(t_img));
	data->img_l = malloc(sizeof(t_img));
	data->map = malloc(sizeof(t_map));
	data->map->bush = malloc(sizeof(t_img));
	data->map->flower = malloc(sizeof(t_img));
	data->map->empty = malloc(sizeof(t_img));
	data->map->out = malloc(sizeof(t_img));
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

void	ft_free_tab(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map2d)
	{
		while (i < data->map->map_line)
		{
			if (data->map->map2d[i])
				free(data->map->map2d[i]);
			i++;
		}
	}
	if (&(data->map->map2d))
	{
		free(data->map->map2d);
		data->map->map2d = NULL;
	}
}

void	free_struct(t_data *data)
{
	if (data->img_r)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_r->image);
		free(data->img_r);
		data->img_r = NULL;
	}
	if (data->img_l)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_l->image);
		free(data->img_l);
		data->img_l = NULL;
	}
	ft_free_tab(data);
	if (data->player)
	{
		free((data->player));
		data->player = NULL;
	}
	if (data->map->bush)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->bush->image);
		free(data->map->bush);
		data->map->bush = NULL;
	}
	if (data->map->flower)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->flower->image);
		free(data->map->flower);
		data->map->flower = NULL;
	}
	if (data->map->empty)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->empty->image);
		free(data->map->empty);
		data->map->empty = NULL;
	}
	if (data->map->out)
	{
		mlx_destroy_image(data->mlx_ptr, data->map->out->image);
		free(data->map->out);
		data->map->out = NULL;
	}
	if (data->map)
		free(data->map);
	data->map = NULL;
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr,data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}