/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:41:35 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/27 16:14:34 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "prc.h"
#include "libft.h"

static int		lunch_cmd(char *cmd, char **argv, t_data *env)
{
	int		i;
	char	**paths;
	char	*tmp;

	i = -1;
	tmp = NULL;
	paths = NULL;
	paths = ft_get_path(env);
	while (paths[++i] != '\0')
	{
		tmp = ft_strjoin(paths[i], cmd);
		execve(tmp, argv, env->env);
		free(tmp);
	}
	execve(cmd, argv, env->env);
	ft_putstr("Command can't be executed, check permission or existence\n");
	exit(-1);
}

int				ft_execve(char *cmd, char **argv, t_data *env)
{
	pid_t	fork_return;
	int		ret;

	ret = -1;
	if ((ret = ft_builtin(cmd, argv, env)) == -1)
	{
		fork_return = fork();
		if (fork_return == 0)
			lunch_cmd(cmd, argv, env);
		else
			waitpid(fork_return, &ret, WUNTRACED);
	}
	return (ret);
}
