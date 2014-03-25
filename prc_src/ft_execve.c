/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:41:35 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/25 19:45:07 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "prc.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/wait.h>

int				ft_builtin(char *cmd, char **argv, t_data *env);

int				ft_execve(char *cmd, char **argv, t_data *env)
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
			paths = ft_get_path(env->env);
			while (paths[++i] != '\0')
			{
				tmp = ft_strjoin(paths[i], cmd);
//				open_dup(link);
				execve(tmp, argv, env->env);
//				close_dup(link);
				free(tmp);
			}
			ft_putstr("not a regular command\n");
			execve(cmd, argv, env->env);
			return (-1);
		}
		else
			waitpid(fork_return, &ret, WUNTRACED);
	}
	return (ret);
}
