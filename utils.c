/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:45:08 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/19 16:52:28 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	victory(t_data *data)
{
	ft_putstr_fd(BOLD GREEN_T"YOU WIN!\n"RESET, 1);
	data->on = -1;
	return (1);
}

int	ft_check_file_ext(char *arg)
{
	int	ext;

	ext = ft_strclen(arg, '.');
	if (ft_strlen(arg) < 5)
		return (-1);
	arg += ext;
	if (ft_strncmp(arg, ".ber", ext) != 0)
		return (-1);
	return (1);
}
