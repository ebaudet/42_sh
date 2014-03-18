/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 09:05:27 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/14 16:15:28 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"

int		ft_exec_tree(t_op **tree, char **env)
{
	int		ret;

	if (((*tree)->lft && (*tree)->lft->stat == 1)
		|| (*tree)->rgt && (*tree)->rgt->stat == 1)
	{
		(*tree)->stat = 0;
		ft_create_op(tree);
		if ((*tree)->lft && (*tree)->lft->stat)
			ret = ft_exec_tree(&(*tree)->lft, env);
		else if ((*tree)->rgt &&(*tree)->rgt->stat)
			ret = ft_exec_tree(&(*tree)->rgt, env);
		if ((*tree)->code == COM)
			ret = ft_execve((*tree)->name, (*tree)->argv, env);
	}
	if ((*tree)->top)
		ret = ft_exec_tree(&(*tree)->top, env);
}
