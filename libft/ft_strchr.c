/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:16:25 by cbignon           #+#    #+#             */
/*   Updated: 2020/12/08 16:31:16 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	x;

	x = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen((char *)s));
	while (s[x])
	{
		if ((unsigned char)s[x] == c)
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}
