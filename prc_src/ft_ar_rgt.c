/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_rgt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 20:55:27 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/25 17:48:41 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "prc.h"

int			ft_ar_rgt(t_op **tmp, t_data *env)
{
	int		fd;
	int		i;
	int		ret;
	int		save;

	save = dup(1);
	fd = -1;
	i = 1;
	ret = 0;
	if ((*tmp)->argv[1])
	{
		fd = open((*tmp)->argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			ret = -1;
	}
	while ((*tmp)->argv[++i])
	{
		ft_putstr((*tmp)->name);
		ft_putstr("no such files or directory\n");
		ret = -1;
	}
	if (ret > -1)
	{
		if ((ret = dup2(fd, 1)) == -1)
			return (ret);
		if ((*tmp)->rgt)
			ft_read_tree((*tmp)->rgt, env);
		else if ((*tmp)->lft)
			ft_read_tree((*tmp)->lft, env);
		if ((ret = dup2(save, 1)) == -1)
			return (ret);
		if ((ret = close(fd)) == -1)
			return (ret);
	}
	if (ret < 0)
		return (ret);
	return (0);
}
