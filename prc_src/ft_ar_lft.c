/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_lft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 01:11:10 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/19 01:44:23 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "prc.h"

int			ft_ar_lft(t_op **tmp)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if ((*tmp)->argv[1])
	{
		(*tmp)->fd_in = open((*tmp)->argv[1], O_RDONLY);
		if ((*tmp)->fd_in == -1)
		{
			ft_putstr((*tmp)->argv[1]);
			ft_putstr(" No such file or directory\n");
			ret = -1;
		}
	}
	if (ret < 0)
		return (ret);
	return (0);
}
