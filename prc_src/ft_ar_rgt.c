/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_rgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 20:55:27 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/19 01:34:33 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "prc.h"

int			ft_ar_rgt(t_op **tmp)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if ((*tmp)->argv[1])
	{
		(*tmp)->fd_out = open((*tmp)->argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if ((*tmp)->fd_out == -1)
			ret = -1;
	}
	while ((*tmp)->argv[++i])
	{
		ft_putstr((*tmp)->name);
		ft_putstr("no such files or directory\n");
		ret = -1;
	}
	if (ret < 0)
		return (ret);
	return (0);
}
