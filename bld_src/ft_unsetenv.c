/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 22:47:50 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/25 22:49:50 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

int		ft_del_env(char **env, int i)
{
	if (!env[i + 1])
	{
		free(env[i]);
		env[i] = NULL;
		return (0);
	}
	free(env[i]);
	while (env[i] && env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
	return (0);
}

int		ft_checkenv_3(char **env, char **arg)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], arg[1], (size_t)ft_strlen(arg[1])) == 0)
		{
			ft_del_env(env, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_checkenv_2(char **env, char **arg)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], arg[1], (size_t)ft_strlen(arg[1])) == 0)
		{
			if (!arg[2])
				return (1);
			else
			{
				ft_checkenv_case2(env, arg, i);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		ft_checkenv_4(char **env, char **arg)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(env[i], arg[1], (size_t)ft_strlen(arg[1])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		ft_unsetenv(char **env, char **arg)
{
	if (ft_checkenv_4(env, arg) == 0)
		return (0);
	ft_checkenv_3(env, arg);
	return (0);
}
