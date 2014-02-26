/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 10:51:32 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 09:00:00 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	size_t		i;

	i = 0;
	if (content)
	{
		ft_memdel(&content);
		content_size = i;
	}
}

static void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list		*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_lst;
	t_list		*tmp;

	new_lst = NULL;
	while (lst != NULL)
	{
		tmp = (t_list *)malloc(sizeof(f(lst)));
		tmp = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (!tmp)
		{
			ft_lstdel(&new_lst, &ft_del);
			return (NULL);
		}
		if (new_lst == NULL)
			new_lst = tmp;
		else
			ft_lstaddend(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}
