/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:38:17 by cbignon           #+#    #+#             */
/*   Updated: 2020/12/16 15:14:19 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nombre;
	char			reste;

	if (n < 0)
	{
		nombre = (unsigned)-(long)n;
		write(fd, "-", 1);
	}
	else
	{
		nombre = n;
	}
	if (nombre >= 10)
	{
		ft_putnbr_fd((nombre / 10), fd);
	}
	reste = nombre % 10 + '0';
	write(fd, &reste, 1);
}
