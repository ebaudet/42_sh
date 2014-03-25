/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_lft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 01:11:10 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/25 17:38:25 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "prc.h"

int			ft_ar_lft(t_op **tmp, t_data *env)
{
	int		fd;
	int		i;
	int		ret;
	int		save;

	save = dup(0);
	fd = -1;
	i = 1;
	ret = 0;
	if ((*tmp)->argv[1])
	{
		fd = open((*tmp)->argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr((*tmp)->argv[1]);
			ft_putstr(" No such file or directory\n");
			ret = -1;
		}
		else
		{
			if ((ret = dup2(fd, save)) == -1)
				return (ret);
			if ((*tmp)->rgt)
				ft_read_tree((*tmp)->rgt, env);
			else if ((*tmp)->lft)
				ft_read_tree((*tmp)->lft, env);
			if ((ret = dup2(save, fd)) == -1)
				return (ret);
			if ((ret = close(fd)) == -1)
				return (ret);
		}
	}
	if (ret < 0)
		return (ret);
	return (0);
}
