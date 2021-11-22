/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:23:26 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/19 17:20:18 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_error(int code, t_data *data)
{
	if (code == 1)
	{
		ft_putstr_fd("ERROR ! can't open map\n", 1);
		ft_simple_free(data),
		exit (0);
	}
	else if (code == 2)
	{
		ft_putstr_fd("ERROR! Invalid map!\n", 1);
		ft_free_tab(data);
		ft_simple_free(data);
		exit (0);
	}
	else if (code == 3)
	{
		ft_putstr_fd("ERROR! Invalid file extension\n", 1);
		exit (1);
	}
	return (-1);
}
