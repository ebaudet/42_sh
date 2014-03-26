/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 16:01:26 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/26 10:57:20 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"

int		ft_and(t_op **and, t_data *env)
{
	int		ret;

	ret = 0;
	if ((ret = ft_read_tree((*and)->rgt, env)) == 0)
		ret = ft_read_tree((*and)->lft, env);
	return (ret);
}

