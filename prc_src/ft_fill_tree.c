/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:38:31 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/11 10:16:53 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "prc.h"
#include "libft.h"
#include <stdlib.h>

void	add_tree(t_tree **tree, t_tree *parent, t_op *lst)
{
	*tree = (t_tree *)malloc(sizeof(t_tree));
	(*tree)->parent = parent;
	(*tree)->left = NULL;
	(*tree)->right = NULL;
	(*tree)->str = ft_strdup(lst->str);
	(*tree)->code = lst->code;
	(*tree)->prior = lst->prior
}

void	ft_fill_tree(t_tree **tree, t_op *lst)
{
	t_op	*tmp;
	t_op	*ret;

	tmp = lst->prev;
	ret = NULL;
	while (tmp && tmp->code > lst->code)
	{
		if (!ret)
			ret = tmp;
		else if (ret->code >= tmp->code)
			ret = tmp;
		tmp = tmp->prev;
	}
	if (ret)
		add_tree(&(*tree)->left, *tree, ret);
	if (ret)
		ft_fill_tree(&(*tree)->left, ret);
	tmp = lst->next;
	ret = NULL;
	while (tmp && tmp->code >= lst->code)
	{
		if (!ret)
			ret = tmp;
		else if (ret->code > tmp->code)
			ret = tmp;
		tmp = tmp->next;
	}
	if (!(*tree)->left && ret)
	{
		add_tree(&(*tree)->left, *tree, ret);
		ft_fill_tree(&(*tree)->left, ret);
	}
	else if (ret)
	{
		add_tree(&(*tree)->right, *tree, ret);
		ft_fill_tree(&(*tree)->right, ret);
	}
}
