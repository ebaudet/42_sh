/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 23:19:17 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/12 19:04:10 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prc.h"

static void		check_left(t_op **tmp, t_op **save)
{
	if (!(*tmp)->lft)
	{
		(*tmp)->lft = *save;
		(*save)->top = *tmp;
	}
	else
	*tmp = (*tmp)->lft;
}

static void		check_right(t_op **tmp, t_op **save)
{
	if (!(*tmp)->rgt)
	{
		(*tmp)->rgt = *save;
		(*save)->top = *tmp;
	}
	else
		*tmp = (*tmp)->rgt;
}

static void		add_tree(t_op **tree, t_op *save)
{
	t_op		*tmp;

	tmp = NULL;
	if (!save)
		return ;
	if (!*tree)
		*tree = save;
	else
	{
		tmp = *tree;
		while (!save->top)
		{
			if (save->nbr < tmp->nbr)
				check_right(&tmp, &save);
			else
				check_left(&tmp, &save);
		}
	}
}

t_op			*ft_create_tree(t_op **lst)
{
	t_op		*tree;
	t_op		*save;
	t_op		*tmp;

	tree = NULL;
	tmp = *lst;
	save = *lst;
	while (save)
	{
		save = NULL;
		while (tmp->next)
		{
			if (!save && tmp->stat == 0)
				save = tmp;
			else if (save && tmp->prior <= save->prior && tmp->stat == 0)
				save = tmp;
			tmp = tmp->next;
		}
		if (save)
			save->stat = 1;
		add_tree(&tree, save);
		tmp = *lst;
	}
	return (tree);
}
