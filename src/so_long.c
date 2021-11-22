/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:34:15 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/19 17:09:54 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *data)
{
	free_struct(data);
	end_mlx(data);
	return (0);
}

void	open_game(t_data *data)
{
	int	screen_x;
	int	screen_y;

	data->map->height = data->map->map_line * 32;
	data->map->width = data->map->map_row * 32;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->width,
			data->map->height, "so_long");
	mlx_get_screen_size(data->mlx_ptr, &screen_x, &screen_y);
	if (data->map->width > screen_x || data->map->height > screen_y)
	{
		ft_putstr_fd("Map is too big for your screen!\n", 1);
		ft_end(data);
		end_mlx(data);
	}
	load_img(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		check;

	if (argc != 2)
	{
		ft_putstr_fd("Error! need 1 arg *.ber\n", 1);
		return (-1);
	}
	check = ft_check_file_ext(argv[1]);
	if (check == -1)
		return (ft_map_error(3, &data));
	init_struct(&data);
	check_map(argv, &data);
	open_game(&data);
	mlx_loop_hook(data.mlx_ptr, &no_event, &data);
	mlx_key_hook(data.win_ptr, &my_key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0L, &ft_end, &data);
	mlx_loop(data.mlx_ptr);
	close_game(&data);
	return (0);
}
