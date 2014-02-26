/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 21:30:50 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/02/26 09:29:46 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_minishell.h"
#include "../libft/libft.h"

void		ft_print_lste(t_edit **lst)
{
	int			mark;
	t_edit		*tmp;

	mark = 0;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (tmp->video == 1)
			mark = 1;
		ft_print_fd(tmp->c);
		tmp = tmp->next;
	}
	if (tmp->video == 1)
		mark = 1;
	ft_print_fd(tmp->c);
	if (mark == 1)
	{
		while (tmp->prev != NULL && tmp->video == 0)
		{
			ft_tputs("le");
			tmp = tmp->prev;
		}
		ft_tputs("le");
	}
}
