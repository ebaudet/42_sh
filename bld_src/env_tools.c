/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 22:34:23 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/26 11:28:42 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"
#include "libft.h"

int		ft_find_equal(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

void	ft_env_display(char **envi)
{
	int		i;

	i = -1;
	while (envi[++i])
	{
		ft_putstr(envi[i]);
		ft_putchar('\n');
	}
}

int		ft_echo_value(char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(line));
	while (line[i] != '=')
		i++;
	while (line[i] != 0)
		tmp[++j] = line[++i];
	tmp[i] = 0;
	ft_putstr(tmp);
	free(tmp);
	return (0);
}

char	**ft_env_copy(char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	while (env[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	tmp[i] = 0;
	i = -1;
	while (env[++i])
		tmp[i] = ft_strdup(env[i]);
	tmp[i] = 0;
	return (tmp);
}

void	ft_free_env(char **envi)
{
	int		i;

	i = -1;
	while (envi[++i])
		free(envi[i]);
	free(envi);
}
