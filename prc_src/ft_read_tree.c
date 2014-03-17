/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:45:52 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/17 18:38:01 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prc.h"

void			change_tmp(t_op **tree, t_op **tmp)
{
	if ((*tmp)->lft && (*tmp)->lft->stat == 1)
		*tmp = (*tmp)->lft;
	else if ((*tmp)->rgt && (*tmp)->rgt->stat == 1)
		*tmp = (*tmp)->rgt;
	else if ((*tmp)->top)
		*tmp = (*tmp)->top;
	if (*tmp == *tree && (*tmp)->stat == 0)
		*tmp = NULL;
}

int				ft_read_tree(t_op **tree, char **env)
{
	int		ret;
	t_op	*tmp;

	ret = 0;
	if (!*tree)
		return (-1);
	tmp = *tree;
	while (tmp)
	{
		if (tmp->code < 7)
			ret = ft_opcode_tree(&tmp, env);
		else
		{
			ret = ft_read_tree(&tmp, env);
			ret = ft_execve(&tmp, env);
		}
		if (ret < 0)
			return (ret);
		change_tmp(tree, &tmp);
	}
	return (0);
}
