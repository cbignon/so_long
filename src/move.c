/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:24:05 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/18 15:14:13 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *data)
{
	// printf("coordonnées de P avant up : %d / %d\n", data->player->x, data->player->y);
	// printf ("map2d[%d][%d] = %c\n", data->player->x, data->player->y,data->map->map2d[data->player->x][data->player->y] );
	if (data->player->x > 1)
	{
		if (data->map->map2d[data->player->x - 1][data->player->y] != '1')
		{
			if (data->map->map2d[data->player->x - 1][data->player->y] == 'C')
			{
				data->player->collected++;
				data->map->coll--;
			}
			else if (data->map->map2d[data->player->x - 1][data->player->y] == 'E')
			{
				if (data->map->coll > 0)
					return (-1);
				else if (data->map->coll == 0)
					return(victory(data));
			}
			data->map->map2d[data->player->x][data->player->y] = '0';
			data->map->map2d[data->player->x - 1][data->player->y] = 'P';
			data->player->x -= 1;
			// printf("coordonnées de P apres move up : %d / %d\n", data->player->x, data->player->y);
			return(0);
		}
		// else if (data->map->map2d[data->player->x - 1][data->player->y] == '1')
		// 	return (-1);
	}
	return (-1);
}

int	move_down(t_data *data)
{
	// printf("coordonnées de P avant down : %d / %d\n", data->player->x, data->player->y);
	// printf ("map2d[%d][%d] = %c\n", data->player->x, data->player->y,data->map->map2d[data->player->x][data->player->y] );
	if (data->player->x < (data->map->map_line - 2))
	{
		if (data->map->map2d[data->player->x + 1][data->player->y] != '1')
		{
			if (data->map->map2d[data->player->x +1][data->player->y] == 'C')
			{
				data->player->collected++;
				data->map->coll--;
			}
			else if (data->map->map2d[data->player->x + 1][data->player->y] == 'E')
			{
				if (data->map->coll > 0)
					return (-1);
				else if (data->map->coll == 0)
					return(victory(data));
			}
			data->map->map2d[data->player->x][data->player->y] = '0';
			data->map->map2d[data->player->x + 1][data->player->y] = 'P';
			data->player->x += 1;
			// printf("coordonnées de P apres move down : %d / %d\n", data->player->x, data->player->y);
			return (0);
		}
		// else
		// 	return (-1);
	}
	return (-1);
}

int	move_right(t_data *data)
{
	// printf("coordonnées de P avant right : %d / %d\n", data->player->x, data->player->y);
	// printf ("map2d[%d][%d] = %c\n", data->player->x, data->player->y,data->map->map2d[data->player->x][data->player->y] );
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
			else if (data->map->map2d[data->player->x][data->player->y + 1] == 'E')
			{
				if (data->map->coll > 0)
					return (-1);
				if (data->map->coll == 0)
					return(victory(data));
			}
			data->map->map2d[data->player->x][data->player->y] = '0';
			data->map->map2d[data->player->x][data->player->y + 1] = 'P';
			data->player->y += 1;
		//	printf("coordonnées de P apres move right : %d / %d\n", data->player->x, data->player->y);
			return (0);
		}
		// else
		// 	return (-1);
	}
	return (-1);
}

int	move_left(t_data *data)
{
	// printf("coordonnées de P avant left : %d / %d\n", data->player->x, data->player->y);
	// printf ("map2d[%d][%d] = %c\n", data->player->x, data->player->y,data->map->map2d[data->player->x][data->player->y] );
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
			else if (data->map->map2d[data->player->x][data->player->y - 1] == 'E')
			{
				if (data->map->coll > 0)
					return (-1);
				else if (data->map->coll == 0)
					return(victory(data));
			}
			data->map->map2d[data->player->x][data->player->y] = '0';
			data->map->map2d[data->player->x][data->player->y - 1] = 'P';
			data->player->y -= 1;
			// printf("coordonnées de P apres move left : %d / %d\n", data->player->x, data->player->y);
			return (0);
		}
		// else
		// 	return (-1);
	}
	return (-1);
}