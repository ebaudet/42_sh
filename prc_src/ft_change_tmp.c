/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_tmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 00:04:15 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/25 00:05:06 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prc.h"

t_op			*change_tmp(t_op *tmp)
{
	t_op		*new;

	new = NULL;
	if (tmp->lft && tmp->lft->stat == 1)
		new = tmp->lft;
	else if (tmp->rgt && tmp->rgt->stat == 1)
		new = tmp->rgt;
	else if (tmp->top)
		new = tmp->top;
	if (!tmp->top && tmp->rgt && tmp->lft && tmp->rgt->stat == 0
		&& tmp->lft->stat == 0)
	{
		new = NULL;
	}
	return (new);
}

