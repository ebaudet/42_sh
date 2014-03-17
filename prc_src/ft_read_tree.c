/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:45:52 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/17 18:14:39 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prc.h"

int				ft_read_tree(t_op **tree, char **env)
{
	t_op	*tmp;

	if (!*tree)
		return (-1);
	tmp = *tree;
	while (tmp)
	{
		if (tmp->code < 7)
			ft_opcode_tree(&tmp, env);
		else
		{
			ft_read_tree(&tmp, env);
			ft_execve(&tmp, env);
		}
		if (tmp->lft && tmp->lft->stat == 1)
			tmp = tmp->lft;
		else if (tmp->rgt && tmp->rgt->stat == 1)
			tmp = tmp->rgt;
		else if (tmp->top)
			tmp = tmp->top;
		if (tmp == *tree && tmp->stat == 0)
			tmp = NULL;
	}
}
