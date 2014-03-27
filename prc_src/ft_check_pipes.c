/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:00:11 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/27 13:44:33 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include "libft.h"

int		ft_check_pipes(t_op **lst)
{
	t_op	*tmp;

	tmp = *lst;
	if (tmp->code == PIPE)
	{
		ft_putstr_fd("pipe error: pipe has no first argument\n", 2);
		return (0);
	}
	while (tmp)
	{
		if (tmp->code == PIPE)
		{
			if (!tmp->next)
			{
				ft_putstr_fd("pipe error: pipe has no second argument\n", 2);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
