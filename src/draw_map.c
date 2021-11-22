/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:59:42 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/20 17:17:20 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_data *data)
{
	ft_load_xpm(data, data->img_r, "./src/graph/fox-right32x32.xpm");
	ft_load_xpm(data, data->img_l, "./src/graph/fox-left32x32.xpm");
	ft_load_xpm(data, data->map->empty, "./src/graph/empty32x32.xpm");
	ft_load_xpm(data, data->map->bush, "./src/graph/Bush32x32.xpm");
	ft_load_xpm(data, data->map->flower, "./src/graph/flower32x32.xpm");
	ft_load_xpm(data, data->map->out, "./src/graph/EXIT32x32.xpm");
}

void	to_win(t_data *data, int j, int i, t_img *img)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->image, j, i);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i * 32 < data->map->height)
	{
		j = 0;
		while (j * 32 < data->map->width)
		{
			if (data->map->map2d[i][j] == '1')
				to_win(data, j * 32, i * 32, data->map->bush);
			if (data->map->map2d[i][j] == 'C')
				to_win(data, j * 32, i * 32, data->map->flower);
			if (data->map->map2d[i][j] == 'P' && data->player->way == 1)
				to_win(data, j * 32, i * 32, data->img_r);
			if (data->map->map2d[i][j] == 'P' && data->player->way == 0)
				to_win(data, j * 32, i * 32, data->img_l);
			if (data->map->map2d[i][j] == '0')
				to_win(data, j * 32, i * 32, data->map->empty);
			if (data->map->map2d[i][j] == 'E')
				to_win(data, j * 32, i * 32, data->map->out);
			j++;
		}
		i++;
	}
}
