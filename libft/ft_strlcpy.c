/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:19:53 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/29 10:12:54 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	x;
	unsigned int	srclen;

	if (!src || !dest)
		return (0);
	x = 0;
	srclen = (ft_strlen((char *)src));
	if (dstsize == 0)
		return (srclen);
	while (x < dstsize - 1 && src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (srclen);
}
