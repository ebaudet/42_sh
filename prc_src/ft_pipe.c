/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 21:22:40 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/26 14:13:22 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "prc.h"
#include "libft.h"

static void		fork_father(int *fd, t_op **tmp, t_data *env)
{
	close(fd[0]);
	dup2(fd[1], 1);
	ft_read_tree((*tmp)->rgt, env);
	exit (0);
}

static int		fork_child(int fork_ret2, int *fd, t_op **tmp, t_data *env)
{
	if ((fork_ret2 = fork()) == -1)
	{
		ft_putstr("fork fail");
		return (-1);
	}
	if (fork_ret2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		ft_read_tree((*tmp)->lft, env);
		exit (0);
	}
	return (0);
}

static void		end_function_pipe(int *fd, int fork_ret, int fork_ret2, int ret)
{
	close(fd[1]);
	close(fd[0]);
	waitpid(fork_ret, &ret, WUNTRACED);
	waitpid(fork_ret2, &ret, WUNTRACED);
}

int				ft_pipe(t_op **tmp, t_data *env)
{
	int		fd[2];
	int		fork_ret;
	int		fork_ret2;
	int		ret;

	ret = 0;
	fork_ret2 = 0;
	fork_ret = 0;
	if (pipe(fd) == -1)
	{
		ft_putstr("pipe fail");
		return (-1);
	}
	if ((fork_ret = fork()) == -1)
	{
		ft_putstr("fork fail");
		return (-1);
	}
	if (fork_ret == 0)
		fork_father(fd, tmp, env);
	if (fork_ret != 0)
		fork_child(fork_ret2, fd, tmp, env);
	end_function_pipe(fd, fork_ret, fork_ret2, ret);
	return (ret);
}
