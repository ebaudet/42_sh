/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 21:22:40 by ymohl-cl          #+#    #+#             */
/*   Updated: 2014/03/25 17:47:56 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prc.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		ft_pipe(t_op **tmp, t_data *env)
{
	int		fd[2];
	int		fork_ret;
	int		fork_ret2;
	int		save_stdout;
	int		save_stdin;
	int		ret;
	int		ret2;

	ret = 0;
	ret2 = 0;
	fork_ret2 = 0;
	fork_ret = 0;
	save_stdout = dup(1);
	save_stdin = dup(0);
	pipe(fd);
	if ((fork_ret = fork()) == -1)
	{
		ft_putstr("fork fail");
		return (-1);
	}
	if (fork_ret == 0)
	{
		close(fd[0]);
		dup2(fd[0], 1);
		ret = ft_read_tree((*tmp)->rgt, env);
		exit (0);
	}
	if (fork_ret != 0)
	{
		if ((fork_ret2 = fork()) == -1)
		{
		ft_putstr("fork fail");
		return (-1);
		}
		if (fork_ret2 == 0)
		{
			close(fd[1]);
			dup2(fd[0],0);
			ret2 = ft_read_tree((*tmp)->lft, env);
			exit (0);
		}
	}
	waitpid(fork_ret, &ret, WUNTRACED);
	dup2(save_stdout, fd[0]);
	close(fd[0]);
	dup2(save_stdin, fd[0]);
	close(fd[0]);
	if (ret < 0 || ret2 < 0)
		return (-1);
	return (ret);
}
