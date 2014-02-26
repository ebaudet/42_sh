/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_thist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 19:31:56 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 09:28:19 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_minishell.h"

static void		clean_lst_e(t_edit *lst)
{
	t_edit		*tmp;

	tmp = NULL;
	if (!lst)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp->video = 0;
		tmp->c = '\0';
		tmp = tmp->next;
		lst->next = NULL;
		lst->prev = NULL;
		free(lst);
		lst = tmp;
	}
	tmp->video = 0;
	tmp->c = '\0';
	lst->next = NULL;
	lst->prev = NULL;
	free(lst);
	lst = NULL;
	tmp = NULL;
}

void			ft_clean_thist(t_hist **hst)
{
	t_hist		*tmp;

	tmp = NULL;
	if (!*hst)
		return ;
	tmp = *hst;
	while (tmp->next != NULL)
	{
		clean_lst_e(tmp->ptr);
		tmp->valid = 0;
		tmp = tmp->next;
		(*hst)->next = NULL;
		(*hst)->prev = NULL;
		free((*hst));
		*hst = tmp;
	}
	clean_lst_e(tmp->ptr);
	tmp->valid = 0;
	(*hst)->next = NULL;
	(*hst)->prev = NULL;
	free((*hst));
	*hst = NULL;
	tmp = NULL;
}
