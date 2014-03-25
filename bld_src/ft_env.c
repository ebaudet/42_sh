/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 22:13:10 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/25 22:17:45 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "header.h"

int		ft_change_value(char *arg, char **env, int i)
{
	int		j;
	int		k;
	char	*tmp;
	char	*tmp2;

	k = 0;
	j = -1;
	tmp2 = (char *)malloc(sizeof(char) * ft_strlen(arg));
	while (env[i][++j] != '=')
		tmp2[j] = env[i][j];
	tmp2[j] = '=';
	tmp2[j + 1] = 0;
	j = -1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(arg));
	while (arg[k] != '=')
		k++;
	while (arg[++k] != 0)
		tmp[++j] = arg[k];
	tmp[j + 1] = 0;
	if (env[i])
		free(env[i]);
	env[i] = ft_strdup(ft_strcat(tmp2, tmp));
	free(tmp);
	free(tmp2);
	return (0);
}

int		ft_check_if_already_exist(char **env, char *arg)
{
	int		i;

	i = -1;
	while (env[++i] != 0)
	{
		if (ft_strncmp(env[i], arg, (size_t)ft_find_equal(arg)) == 0)
		{
			ft_change_value(arg, env, i);
			return (1);
		}
	}
	return (0);
}

void	ft_env_add(t_data *data, char **arg)
{
	int		j;
	int		i;
	char	**tmp;

	i = -1;
	j = 0;
	tmp = data->env;
	if (ft_check_if_already_exist(data->env, arg[1]) == 1)
		return ;
	while (data->env[j] != 0)
		j++;
	data->env = (char **)malloc(sizeof(char *) * (j + 3));
	while (tmp[++i] != 0)
		data->env[i] = ft_strdup(tmp[i]);
	data->env[i] = ft_strdup(arg[1]);
	data->env[i + 1] = 0;
}

int		ft_val_to_env(t_data *data, char **arg)
{
	int		i;

	i = -1;
	while (arg[1][++i] != 0)
	{
		if (arg[1][i] == '=')
		{
			ft_env_add(data, arg);
			return (1);
		}
	}
	ft_putstr("env: ");
	ft_putstr(arg[1]);
	ft_putstr(": No such file or directory\n");
	return (0);
}

int		ft_env(t_data *data, char **arg)
{
	if (!arg[1])
		ft_env_display(data->env);
	else
		ft_val_to_env(data, arg);
	return (0);
}
