/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opcode_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 18:47:24 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/25 10:03:12 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include "libft.h"

int			ft_opcode_tree(t_op **tmp, char **env)
{
	int		ret;

	ret = 0;
	(void)env;
	if ((*tmp)->code == 0)
		ret = ft_semicol(tmp, env);
	else if ((*tmp)->code == 1)
		;
//		ret = ft_and();
	else if ((*tmp)->code == 2)
		;
//		ret = ft_or();
	else if ((*tmp)->code == 3)
		;
//		ret = ft_pipe();
	else if ((*tmp)->code == 4)
		ret = ft_ar_lft(tmp, env);
	else if ((*tmp)->code == 5)
		ret = ft_ar_rgt(tmp, env);
	else if ((*tmp)->code == 6)
		ret = ft_db_ar_rgt(tmp, env);
	return (0);
}

