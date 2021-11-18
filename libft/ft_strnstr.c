/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:10:07 by cbignon           #+#    #+#             */
/*   Updated: 2021/09/29 10:10:51 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[x] != '\0' && x < n)
	{
		y = 0;
		while (x + y < n && s2[y] == s1[x + y] && s2[y] != '\0')
		{
			y++;
			if (s2[y] == '\0')
				return ((char *)s1 + x);
		}
		x++;
	}
	return (NULL);
}
