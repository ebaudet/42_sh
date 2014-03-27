/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 22:52:25 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/27 23:03:08 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

void	ft_checkenv_case2(char **env, char **arg, int i)
{
	char	*tmp;
	int		j;
	int		k;

	j = -1;
	k = -1;
	tmp = ft_strdup(env[i]);
	free(env[i]);
	env[i] = (char *)malloc(sizeof(char) *
	(ft_strlen(env[i] + ft_strlen(arg[2]))));
	while (tmp[++k] != '=')
		env[i][k] = tmp[k];
	env[i][k] = tmp[k];
	k++;
	while (arg[2][++j] != 0)
		env[i][k++] = arg[2][j];
	env[i][k] = 0;
	free(tmp);
}

int		ft_check_args(char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
		i++;
	if (i != 3)
	{
		ft_putstr("usage: setenv [var1] [var2].\n");
		return (-1);
	}
	return (0);
}

static void		free_tmp(char **tmp1, char **tmp2)
{
	free(*tmp1);
	free(*tmp2);
	*tmp1 = NULL;
	*tmp2 = NULL;
}

void	ft_setenv(t_data *data, char **arg)
{
	int		j;
	int		i;
	char	**tmp;
	char	*temp;
	char	*temp2;

	temp = NULL;
	i = -1;
	j = 0;
	if (ft_check_args(arg) == -1)
		return ;
	tmp = data->env;
	if (ft_checkenv_2(data->env, arg) == 1)
		return ;
	while (data->env[j] != 0)
		j++;
	data->env = (char **)malloc(sizeof(char *) * (j + 2));
	while (tmp[++i] != 0)
		data->env[i] = tmp[i];
	temp2 = ft_strjoin(arg[1], "=");
	if (arg[2])
		temp = ft_strjoin(temp2, arg[2]);
	data->env[i] = ft_strdup(temp);
	data->env[i + 1] = 0;
	free_tmp(&temp, &temp2);
}

int		ft_checkenv(char **env, char *str)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		if (ft_strcmp(env[i], str) == 0)
			return (1);
		i++;
	}
	ft_putstr("[ENV] - Not Found.\n");
	return (0);
}
