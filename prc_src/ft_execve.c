/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 14:41:35 by wbeets            #+#    #+#             */
/*   Updated: 2014/03/17 20:41:34 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_execve(char *cmd, char **argv, char **env)
{
	pid_t	fork_return;
	char	**paths;
	char	*tmp;
	int		i;
	int		ret;

	ret = 0;
	i = -1;
	if ((ret = ft_builtin(cmd, argv, env) == -1))
	{
		fork_return = fork();
		if (fork_return == 0)
		{
			paths = ft_get_paths(env);
			ft_putstr("in_child");
			while (paths[++i] != '\0')
			{
				tmp = ft_strjoin(paths[i], cmd);
				execve(tmp, argv, env);
				free(tmp);
			}
		}
		else
		{
			waitpid(fork_return, &ret);
		}
	}
	return (ret);
}
