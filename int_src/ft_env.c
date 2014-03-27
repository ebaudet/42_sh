/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 21:13:08 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/14 00:42:42 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell.h"
#include "libft.h"

static int	ft_count_c(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

char		**ft_get_path(t_data *env)
{
	char	**path;
	char	**tmp;
	int		i;
	int		j;

	if ((tmp = ft_strsplit(env->path, ':')) == NULL)
		return (NULL);
	i = ft_count_c(env->path, ':') + 1;
	if ((path = (char **)malloc(i * sizeof(char *))) == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		if ((path[j] = ft_strjoin(tmp[j], "/")) == NULL)
			return (NULL);
		free(tmp[j]);
		j++;
	}
	path[i] = NULL;
	free(tmp);
	return (path);
}
