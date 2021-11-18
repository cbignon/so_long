/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:23:26 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/18 18:25:31 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_error(int code, t_data *data)
{
	if (code == 1)
		ft_putstr_fd("ERROR ! can't open map\n", 1);
	else if (code == 2)
		ft_putstr_fd("ERROR! Invalid map!\n", 1);
	if (data->img_r)
	{
		free(data->img_r);
		data->img_r = NULL;
	}
	if (data->img_l)
	{
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
		free(data->map->bush);
		data->map->bush = NULL;
	}
	if (data->map->flower)
	{
		free(data->map->flower);
		data->map->flower = NULL;
	}
	if (data->map->empty)
	{
		free(data->map->empty);
		data->map->empty = NULL;
	}
	if (data->map->out)
	{
		free(data->map->out);
		data->map->out = NULL;
	}
	if (data->map)
		free(data->map);
	exit (1);
	return (-1);
}