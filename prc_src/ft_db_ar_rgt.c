/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_ar_rgt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 01:12:22 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/25 17:39:48 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "prc.h"

static void		print_two_string(char *s1, char *s2)
{
	ft_putstr(s1);
	ft_putstr(s2);
}

static int		do_dup(int fd, t_op **tmp, char **env)
{
	int		ret;
	int		save;

	save = dup(1);
	ret = 0;
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
	return (0);
}

int			ft_db_ar_rgt(t_op **tmp, char **env)
{
	int		fd;
	int		ret;
	int		i;

	i = ret = 1;
	fd = -1;
	if ((*tmp)->argv[1])
	{
		fd = open((*tmp)->argv[1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			ret = -1;
	}
	while ((*tmp)->argv[++i])
	{
		print_two_string((*tmp)->name, "no such files or directory\n");
		ret = -1;
	}
	if (ret > -1)
	{
		if ((ret = do_dup(fd, tmp, env)) < 0)
			return (ret);
	}
	if (ret < 0)
		return (ret);
	return (0);
}
