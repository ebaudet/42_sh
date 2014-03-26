/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_left_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:15:54 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 15:26:46 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdlib.h>
#include "ft_minishell.h"

static void		arrow_left(t_edit **tmp, t_edit **lst, struct winsize ws)
{
	int		i;

	i = 0;
	if ((*tmp)->video == 0 && ((ft_pcur(lst) + 4) % ws.ws_col) == 0)
	{
		(*tmp)->video = 1;
		ft_tputs("up");
		i = -1;
		while (++i < ws.ws_col)
			ft_tputs("nd");
	}
	else if ((*tmp)->video == 0)
	{
		(*tmp)->video = 1;
		ft_tputs("le");
	}
	else if ((*tmp)->video == 1 && (*tmp)->prev != NULL)
	{
		(*tmp)->video = 0;
		(*tmp)->prev->video = 1;
		ft_tputs("le");
	}
}

static void		arrow_right(t_edit **tmp, t_edit **lst, struct winsize ws)
{
	if ((*tmp)->video == 1 && ((ft_pcur(lst) + 4) % ws.ws_col) == 0)
	{
		(*tmp)->video = 0;
		if ((*tmp)->next != NULL)
			(*tmp)->next->video = 1;
		ft_tputs("do");
	}
	else if ((*tmp)->video == 1)
	{
		(*tmp)->video = 0;
		if ((*tmp)->next != NULL)
			(*tmp)->next->video = 1;
		ft_tputs("nd");
	}
}

void			ft_arrow_left_right(t_edit **lst, char *key, struct winsize ws)
{
	t_edit		*tmp;

	tmp = *lst;
	while (tmp->next != NULL && tmp->video == 0)
		tmp = tmp->next;
	if (ARROW && ARROW_LEFT && tmp->video > -1)
		arrow_left(&tmp, lst, ws);
	else if (ARROW && ARROW_RIGHT && tmp->video > -1)
		arrow_right(&tmp, lst, ws);
}
