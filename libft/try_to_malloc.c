/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:00:23 by cbignon           #+#    #+#             */
/*   Updated: 2021/10/28 12:00:26 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*try_to_malloc(char *src, int size)
{
	char	*dest;

	dest = malloc(sizeof(char) * size);
	if (dest == NULL)
		return ((void *)(unsigned long long)free_str(&src));
	return (dest);
}
