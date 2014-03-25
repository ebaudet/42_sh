/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:25:03 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/25 22:57:06 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "libft.h"

int		ft_builtin_help(char *cmd, char **argv, t_data *data)
{
	if (ft_strcmp(cmd, "echo") == 0)
	{
		ft_echo(argv, data->env);
		return (1);
	}
	else if (ft_strcmp(cmd, "env") == 0)
	{
		ft_env(data, argv);
		return (1);
	}
	else if (ft_strcmp(cmd, "exit") == 0)
		exit(0);
	return (0);
}

void	ft_cd_help(t_data *data, char **argv)
{
	if (!argv[1])
		chdir(data->home);
	else if (ft_strcmp(argv[1], "~") == 0)
		chdir(data->home);
	else if (ft_strcmp(argv[1], "-") == 0)
		chdir(data->old_pwd);
	else
		chdir(argv[1]);
	data->old_pwd = data->pwd;
}

int		ft_builtin(char *cmd, char **argv, t_data *data)
{
	if (ft_strcmp(cmd, "setenv") == 0 && argv[1])
	{
		ft_setenv(data, argv);
		return (1);
	}
	else if (ft_strcmp(cmd, "unsetenv") == 0 && argv[1])
	{
		ft_unsetenv(data->env, argv);
		return (1);
	}
	else if (ft_strcmp(cmd, "cd") == 0)
	{
		ft_cd_help(data, argv);
		return (1);
	}
	else if (ft_builtin_help(cmd, argv, data) == 1)
		return (1);
	return (-1);
}
