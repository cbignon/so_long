/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:13:28 by cbignon           #+#    #+#             */
/*   Updated: 2021/10/28 10:14:09 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup_clean(const char *s)
{
	char	*str;
	char	*dup;
	int		len;
	int		x;

	str = (char *)s;
	len = ft_strlen(str);
	x = 0;
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!(dup))
		return (NULL);
	while (x < len)
	{
		dup[x] = str[x];
		x++;
	}
	dup[x] = '\0';
	if (s)
		free((char *)s);
	return (dup);
}