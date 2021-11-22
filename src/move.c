/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:24:05 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/19 16:29:43 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *data)
{
	if (data->player->x > 1)
	{
		if (data->map->map2d[data->player->x - 1][data->player->y] != '1')
		{
			if (data->map->map2d[data->player->x - 1][data->player->y] == 'C')
			{
				data->player->collected++;
				data->map->coll--;
			}
			else if (data->map->map2d[data->player->x - 1][data->player->y]
				== 'E')
			{
				if (data->map->coll > 0)
					return (-1);
				else if (data->map->coll == 0)
					return (victory(data));
			}
			data->map->map2d[data->player->x][data->player->y] = '0';
			data->map->map2d[data->player->x - 1][data->player->y] = 'P';
			data->player->x -= 1;
			return (0);
		}
	}
	return (-1);
}

int	move_down(t_data *data)
{
	if (data->player->x < (data->map->map_line - 2))
	{
		if (data->map->map2d[data->player->x + 1][data->player->y] != '1')
		{
			if (data->map->map2d[data->player->x +1][data->player->y] == 'C')
			{
				data->player->collected++;
				data->map->coll--;
			}
			else if (data->map->map2d[data->player->x + 1][data->player->y]
				== 'E')
			{
				if (data->map->coll > 0)
					return (-1);
				else if (data->map->coll == 0)
					return (victory(data));
			}
			data->map->map2d[data->player->x][data->player->y] = '0';
			data->map->map2d[data->player->x + 1][data->player->y] = 'P';
			data->player->x += 1;
			return (0);
		}
	}
	return (-1);
}

int	move_right(t_data *data)
{
	data->player->way = 1;
	if (data->player->y < (data->map->map_row - 2))
	{
		if (data->map->map2d[data->player->x][data->player->y + 1] != '1')
		{
			if (data->map->map2d[data->player->x][data->player->y + 1] == 'C')
			{
				data->player->collected++;
				data->map->coll--;
			}
			else if (data->map->map2d[data->player->x][data->player->y + 1]
				== 'E')
			{
				if (data->map->coll > 0)
					return (-1);
				if (data->map->coll == 0)
					return (victory(data));
			}
			data->map->map2d[data->player->x][data->player->y] = '0';
			data->map->map2d[data->player->x][data->player->y + 1] = 'P';
			data->player->y += 1;
			return (0);
		}
	}
	return (-1);
}

int	move_left(t_data *data)
{
	data->player->way = 0;
	if (data->player->y > 1)
	{
		if (data->map->map2d[data->player->x][data->player->y - 1] != '1')
		{
			if (data->map->map2d[data->player->x][data->player->y - 1] == 'C')
			{
				data->player->collected++;
				data->map->coll--;
			}
			else if (data->map->map2d[data->player->x][data->player->y - 1]
				== 'E')
			{
				if (data->map->coll > 0)
					return (-1);
				else if (data->map->coll == 0)
					return (victory(data));
			}
			data->map->map2d[data->player->x][data->player->y] = '0';
			data->map->map2d[data->player->x][data->player->y - 1] = 'P';
			data->player->y -= 1;
			return (0);
		}
	}
	return (-1);
}
