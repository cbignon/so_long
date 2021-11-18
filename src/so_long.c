/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:34:15 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/18 18:02:14 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Error! need 1 arg *.ber\n", 1);
		return (-1);
	}
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