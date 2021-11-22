/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:04:29 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/19 16:31:03 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (1);
}

void	end_mlx(t_data *data)
{
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}

int	no_event(t_data *data)
{
	draw_map(data);
	if (data->on == -1)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	my_key_hook(int key, t_data *data)
{
	int	ret;

	ret = -1;
	if (key == KEY_A)
		ret = move_left(data);
	else if (key == KEY_D)
		ret = move_right(data);
	else if (key == KEY_S)
		ret = move_down(data);
	else if (key == KEY_W)
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
	return (0);
}
