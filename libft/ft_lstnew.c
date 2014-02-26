/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 10:59:38 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 09:00:18 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list)
	{
		if (content)
		{
			new_list->content = malloc(sizeof(content_size));
			if (new_list->content)
			{
				ft_memcpy(new_list->content, content, content_size);
				new_list->content_size = content_size;
				new_list->next = NULL;
				return (new_list);
			}
		}
		new_list->content = NULL;
		new_list->content_size = 0;
		new_list->next = NULL;
		return (new_list);
	}
	return (NULL);
}
