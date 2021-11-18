/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:12:11 by cbignon           #+#    #+#             */
/*   Updated: 2020/12/18 11:34:57 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **head, t_list *element)
{
	t_list	*ptr;

	ptr = *head;
	if (!*head)
	{
		*head = element;
		return ;
	}
	if (ptr && element)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = element;
	}
}
