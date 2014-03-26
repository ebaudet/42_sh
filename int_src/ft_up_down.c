/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_up_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:16:12 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 15:24:55 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdlib.h>
#include "ft_minishell.h"

static void	arrow_up(t_hist **tmp, t_edit **lst)
{
	while ((*tmp)->next != NULL && (*tmp)->valid == 0)
		*tmp = (*tmp)->next;
	if ((*tmp)->next != NULL)
	{
		*lst = (*tmp)->next->ptr;
		(*tmp)->next->valid = 1;
		(*tmp)->valid = 0;
	}
}

static void	arrow_down(t_hist **tmp, t_edit **lst)
{
	while ((*tmp)->next != NULL && (*tmp)->valid == 0)
		*tmp = (*tmp)->next;
	if ((*tmp)->prev != NULL)
	{
		*lst = (*tmp)->prev->ptr;
		(*tmp)->valid = 0;
		(*tmp)->prev->valid = 1;
	}
}

void		ft_up_down(t_edit **lst, t_hist **hst, char *key, struct winsize ws)
{
	t_hist		*tmp;

	tmp = NULL;
	if (*hst)
	{
		tmp = *hst;
		if (ARROW && key[2] == 65 && key[3] == 0)
			arrow_up(&tmp, lst);
		else
			arrow_down(&tmp, lst);
		ft_tputs("rc");
		ft_tputs("cd");
		ft_print_lste(lst);
	}
	if (((ft_poscurseur(lst) + 4) % ws.ws_col) == 0)
		ft_tputs("do");
}
