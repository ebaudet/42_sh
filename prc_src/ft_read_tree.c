/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:45:52 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/25 17:15:54 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prc.h"
#include "libft.h"

int				ft_read_tree(t_op *tree, t_data *env)
{
	int		ret;

	ret = 0;
	if (!tree)
		return (-1);
	if (tree)
	{
		if (tree->code < 7)
			ret = ft_opcode_tree(&tree, env);
		else if (tree->code == 7)
			ret = ft_execve(tree->name, tree->argv, env);
	}
	return (ret);
}
