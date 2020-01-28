/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jumprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:15:39 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/27 21:18:02 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		ft_jumprint(t_edit **lst)
{
	int				jump;
	int				i;
	struct winsize	ws;

	get_winsize(&ws);
	i = 0;
	jump = ((l_list(lst) + 3) / ws.ws_col) - ((ft_pcur(lst) + 3) / ws.ws_col);
	if (!(((l_list(lst) + 3) % ws.ws_col) == 0))
	{
		while (i < jump)
		{
			ft_tputs("do");
			i++;
		}
	}
}
