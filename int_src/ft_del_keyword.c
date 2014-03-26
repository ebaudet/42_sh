/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_keyword.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:50:33 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 15:08:04 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"
#include <sys/ioctl.h>

static void		video_one_cont(t_edit **tmp)
{
	(*tmp)->c = '\0';
	(*tmp)->prev->next = (*tmp)->next;
	(*tmp)->next->prev = (*tmp)->prev;
	free(*tmp);
	ft_tputs("le");
	ft_tputs("dc");
}

static void		video_one(t_edit **tmp, t_edit **lst, t_hist **hst)
{
	t_hist		*tmp_hst;

	tmp_hst = *hst;
	while (tmp_hst->next != NULL && tmp_hst->valid == 0)
		tmp_hst = tmp_hst->next;
	*tmp = (*tmp)->prev;
	if ((*tmp)->prev == NULL)
	{
		tmp_hst->ptr = (*tmp)->next;
		*lst = (*tmp)->next;
		(*tmp)->c = '\0';
		(*tmp)->video = 0;
		(*lst)->prev = NULL;
		(*tmp)->next = NULL;
		free(*tmp);
		ft_tputs("le");
		ft_tputs("dc");
	}
	else
		video_one_cont(tmp);
}

static t_edit		**video_zero(t_edit *tmp, t_edit **lst)
{
	if (tmp->prev == NULL)
	{
		tmp->c = '\0';
		tmp->video = -1;
		ft_tputs("le");
		ft_tputs("dc");
	}
	else
	{
		tmp->prev->next = NULL;
		tmp->video = 0;
		tmp->c = '\0';
		free(tmp);
		ft_tputs("le");
		ft_tputs("dc");
	}
	return (lst);
}

void			ft_del_keyword(t_edit **lst, t_hist **hst, struct winsize ws)
{
	t_edit		*tmp;

	tmp = NULL;
	tmp = *lst;
	if (tmp->video == -1)
		return ;
	while (tmp->next != NULL && tmp->video == 0)
		tmp = tmp->next;
	if (tmp->prev == NULL && tmp->video == 1)
		return ;
	if (tmp->video == 0)
		video_zero(tmp, lst);
	else
		video_one(&tmp, lst, hst);
	print_commande(lst, ws);
}
