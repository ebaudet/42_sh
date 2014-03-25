/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:41:35 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/25 10:07:05 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "prc.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/wait.h>
#include "header.h"

/*static int		open_dup(t_op **link)
{
	int		ret;
	t_op	*tmp;

	ret = 0;
	tmp = *link;
	if (tmp->top)
	{
		tmp = tmp->top;
		if (tmp->fd_out > 1)
		{
			if ((ret = dup2(tmp->fd_out, 1)) == -1)
				return (ret);
		}
		if (tmp->fd_in > 0)
		{
			if ((ret = dup2(tmp->fd_in, 0)) == -1)
				return (ret);
		}
	}
	return (ret);
}

static int		close_dup(t_op **link)
{
	int		ret;
	t_op	*tmp;

	ret = 0;
	tmp = *link;
	if (tmp->top)
	{
		tmp = tmp->top;
		if (tmp->fd_out > 1)
		{
			if ((ret = dup2(1, tmp->fd_out)) == -1)
				return (ret);
			if ((ret = close(tmp->fd_out)) == -1)
				return (ret);
		}
		if (tmp->fd_in > 0)
		{
			if ((ret = dup2(0, tmp->fd_in)) == -1)
				return (ret);
			if ((ret = close(tmp->fd_in)) == -1)
				return (ret);
		}
	}
	return (ret);
}*/

int				ft_execve(char *cmd, char **argv, char **env)
{
	pid_t	fork_return;
	char	**paths;
	char	*tmp;
	int		i;
	int		ret;

	ret = -1;
	i = -1;
	if ((ret = ft_builtin(cmd, argv, env)) == -1)
	{
		fork_return = fork();
		if (fork_return == 0)
		{
			paths = ft_get_path(env);
			while (paths[++i] != '\0')
			{
				tmp = ft_strjoin(paths[i], cmd);
//				open_dup(link);
				execve(tmp, argv, env);
//				close_dup(link);
				free(tmp);
			}
			ft_putstr("not a regular command\n");
			execve(cmd, argv, env);
			return (-1);
		}
		else
		{
			waitpid(fork_return, &ret, WUNTRACED);
		}
	}
	return (ret);
}
