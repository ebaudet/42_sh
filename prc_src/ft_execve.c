/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:41:35 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/18 18:24:39 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "prc.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/wait.h>
#include "header.h"

int		ft_execve(char *cmd, char **argv, char **env)
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
				ft_putstr(tmp);
				ft_putstr("\n");
				execve(tmp, argv, env);
				free(tmp);
			}
			ft_putstr("not a regular command\n");
			execve(cmd, argv, env);
			exit(0);
		}
		else
		{
			waitpid(fork_return, &ret, WUNTRACED);
		}
	}
	return (ret);
}
