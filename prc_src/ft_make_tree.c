/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:45:20 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/11 10:11:55 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "prc.h"
#include "libft.h"

static t_op		*find_start(t_op *oplst)
{
	t_op	*tmp;
	t_op	*ret;
	int		code;

	code = 5;
	ret = NULL;
	tmp = oplst;
	while (tmp)
	{
		if (tmp->code < code)
		{
			ret = tmp;
			code  = tmp->code;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	init_tree(t_tree **tree, t_op *start)
{
	*tree = (t_tree *)malloc(sizeof(t_tree));
	(*tree)->parent = NULL;
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->str = ft_strdup(start->str);
	(*tree)->code = start->code;
}

t_tree	*ft_make_tree(t_op *oplst)
{
	t_op	*start;
	t_tree	*tree;

	tree = NULL;
	start = find_start(oplst);
	init_tree(&tree, start);
	ft_fill_tree(&tree, start);
	return (tree);
}
