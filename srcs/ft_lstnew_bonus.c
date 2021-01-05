/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:48:13 by mqueguin          #+#    #+#             */
/*   Updated: 2020/11/12 19:25:15 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*new_element;

	if (!(new_element = (t_list*)malloc(sizeof(t_list))))
		return NULL;
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}
