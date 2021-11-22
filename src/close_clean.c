/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:50:08 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/19 16:22:37 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_destroy_img(t_img *img, t_data *data)
{
	if (img->image)
		mlx_destroy_image(data->mlx_ptr, img->image);
	if (img)
		free(img);
	img = NULL;
}

void	ft_free_img(t_img *img)
{
	if (img)
		free(img);
	img = NULL;
}

void	ft_simple_free(t_data *data)
{
	if (data->player)
	{
		free((data->player));
		data->player = NULL;
	}
	ft_free_img(data->img_r);
	ft_free_img(data->img_l);
	ft_free_img(data->map->empty);
	ft_free_img(data->map->out);
	ft_free_img(data->map->flower);
	ft_free_img(data->map->bush);
	if (data->map)
	{
		free(data->map);
		data->map = NULL;
	}
}

void	free_struct(t_data *data)
{
	if (data->img_r->image)
		ft_destroy_img(data->img_r, data);
	if (data->img_l)
		ft_destroy_img(data->img_l, data);
	if (data->map->bush)
		ft_destroy_img(data->map->bush, data);
	if (data->map->flower)
		ft_destroy_img(data->map->flower, data);
	if (data->map->empty)
		ft_destroy_img(data->map->empty, data);
	if (data->map->out)
		ft_destroy_img(data->map->out, data);
	ft_free_tab(data);
	if (data->player)
	{
		free((data->player));
		data->player = NULL;
	}
	if (data->map)
		free(data->map);
	data->map = NULL;
}
