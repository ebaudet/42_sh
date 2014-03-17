/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:45:52 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/17 20:40:49 by ymohl-cl         ###   ########.fr       */
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

int				ft_read_tree(t_op *tree, char **env)
{
	int		ret;
	t_op	*tmp;
	t_op	*save;

	ret = 0;
	if (!tree)
		return (-1);
	save = NULL;
	tmp = tree;
	while (tmp)
	{
		if (tmp->code < 7 && tmp->stat == 1)
		{
			ret = ft_opcode_tree(&tmp, env);
			tmp->stat = 0;
		}
		else if (tmp->code == 7 && tmp->stat == 1)
		{
			save = change_tmp(tmp);
			tmp->stat = 0;
			ret = ft_read_tree(tmp, env);
			ret = ft_execve(tmp->name, tmp->argv, env);
		}
		tmp = change_tmp(tmp);
		if (ret < 0)
			return (ret);
	}
	return (0);
}
