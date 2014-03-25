/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 09:54:58 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/25 17:46:57 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"

int		ft_or(t_op **and, t_data *env)
{
	int		ret;

	ret = 0;
	if ((ret = ft_read_tree((*and)->rgt, env)) < 0)
		ret = ft_read_tree((*and)->lft, env);
	return (ret);
}
